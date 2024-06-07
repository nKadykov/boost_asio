#pragma once
#include <boost/asio.hpp>
#include <deque>

class GameClient {
public:
    GameClient(boost::asio::io_context& io_context, const std::string& host, const std::string& port);
    void write(const std::string& message);
    void close();
private:
    void read();
    void write();

    boost::asio::ip::tcp::socket m_socket;
    boost::asio::streambuf m_response;
    std::deque<std::string> m_message;
};