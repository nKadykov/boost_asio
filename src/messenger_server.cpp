#include <iostream>
#include <boost/asio.hpp>

int main() {
    // контекст для выполнения асинхронных операций ввода/вывода
    boost::asio::io_context io_service;
    // объект, который прослушивание входящие соединения на указанном порту
    boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8080));
    // бесконечный цикл для обработки входящих соединение
    while(true) {
        boost::asio::ip::tcp::socket socket(io_service);
        acceptor.accept(socket);
    }
    return 0;
}