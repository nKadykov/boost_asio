#include <iostream>
#include "game_session.h"

GameSession::GameSession(boost::asio::ip::tcp::socket socket) : m_socket(std::move(socket)) {}

void GameSession::start() {
    do_read();
}

void GameSession::do_read() {
    auto self(shared_from_this());
    m_socket.async_read_some(boost::asio::buffer(m_data),
        [this, self](boost::system::error_code error_code, std::size_t length) {
            if(!error_code) {
                do_write(length);
            }
        });
}

void GameSession::do_write(std::size_t length) {
    auto self(shared_from_this());
    boost::asio::async_write(m_socket, boost::asio::buffer(m_data, length),
        [this, self](boost::system::error_code error_code, std::size_t) {
            if(!error_code) {
                do_read();
            }
        });
}