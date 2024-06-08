#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>

void handle_client(boost::asio::ip::tcp::socket socket, boost::asio::yield_context yield) {
    using namespace boost::asio;
    try {
        char data[512];
        for(;;) {
            std::size_t length = socket.async_read_some(buffer(data), yield);
            if(length > 0) {
                async_write(socket, buffer(data, length), yield);
            }
        }
    } catch(std::exception& ex) {
        std::cerr << "Exception in handle_client: " << ex.what() << "\n";
    } 
}

void accept_connection(boost::asio::io_context& io_context, unsigned short port, boost::asio::yield_context yield) {
    using namespace boost::asio;
    ip::tcp::acceptor acceptor(io_context, ip::tcp::endpoint(ip::tcp::v4(), port));
    for(;;) {
        ip::tcp::socket socket(io_context);
        acceptor.async_accept(socket, yield);
        spawn(io_context, std::bind(handle_client, std::move(socket), std::placeholders::_1));
    }
}

int main() {
    using namespace boost::asio;
    try {
        // объект управления асинхронными операциями
        io_context io_context;
        // запуск корутины, которая принимает соединения и обрабатывает их
        spawn(io_context, std::bind(accept_connection, std::ref(io_context)));
        // запуск цикл событий и выполняет все асинхронные операции
        io_context.run();
    } catch(std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << "\n";
    }

    return 0;
}