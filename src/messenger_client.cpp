#include <iostream>
#include <boost/asio.hpp>

int main() {
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket(io_service);
    boost::asio::ip::tcp::resolver resolver(io_service);
    boost::asio::connect(socket, resolver.resolve({"localhost", "8080"}));

    return 0;
}