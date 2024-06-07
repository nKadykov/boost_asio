#include "game_client.h"
#include <iostream>

GameClient::GameClient(boost::asio::io_context& io_context, const std::string& host, const std::string& port) : m_socket(io_context) {
    boost::asio::ip::tcp::resolver resolver(io_context);
    boost::asio::connect(m_socket, resolver.resolve(host, port));
    read();
}

void GameClient::write(const std::string& message) {
    boost::asio::post(m_socket.get_executor(), [this, message]() {
        bool write_in_progress = !m_message.empty();
        m_message.push_back(message);
        if(!write_in_progress) {
            write();
        }
    });
}

void GameClient::close() {
    boost::asio::post(m_socket.get_executor(), [this]() {
        m_socket.close();
    });
}

void GameClient::read() {
    boost::asio::async_read_until(m_socket, m_response, '\n',
        [this](boost::system::error_code error, std::size_t) {
            if(!error) {
                std::istream is(&m_response);
                std::string line;
                std::getline(is, line);
                std::cout << "Server: " << line << "\n";
                read();
            }
        });
}

void GameClient::write() {
    boost::asio::async_write(m_socket, boost::asio::buffer(m_message.front().data(), m_message.front().size()), [this](boost::system::error_code error, std::size_t) {
        if(!error) {
            m_message.pop_front();
            if(!m_message.empty()) {
                write();
            }
        }
    });
}