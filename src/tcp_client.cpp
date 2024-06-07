#include <boost/asio.hpp>
#include <iostream>

int main() {
    using boost::asio::ip::tcp;
    try {
        // инициализация io_context
        boost::asio::io_context io_context;
        // создание резолвера для получения конечной точки подключения
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("127.0.0.1", "12345");
        // создание и поключение сокета
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);
        // отправка сообщения серверу
        std::string request = "Hello from client!";
        boost::asio::write(socket, boost::asio::buffer(request));
        // чтение ответа от сервера
        char reply[1024];
        size_t reply_length = boost::asio::read(socket, boost::asio::buffer(reply, request.size()));
        std::cout << "Reply is: ";
        std::cout.write(reply, reply_length);
        std::cout << std::endl;
    } catch(std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}