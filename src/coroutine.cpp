#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <iostream>

// асинхронное чтение из сокета 
void async_read(boost::asio::ip::tcp::socket& socket, boost::asio::yield_context yield) {
    try {
        char data[128];
        // асинхронное чтение данных в буфер
        std::size_t n = socket.async_read_some(boost::asio::buffer(data), yield);
        std::cout.write(data, n);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

int main() {
    try {
        // объект управления асинхронными операциями
        boost::asio::io_context io_context;
        // объект для поиска конечных точек по имени хоста и порту
        boost::asio::ip::tcp::resolver resolver(io_context);
        boost::asio::ip::tcp::resolver::results_type endpoints =
            resolver.resolve("example.com", "daytime");
        // создание tcp сокета
        boost::asio::ip::tcp::socket socket(io_context);
        // асинхронное подключение к конечным точкам
        boost::asio::async_connect(socket, endpoints,
            [&](const boost::system::error_code& ec, const boost::asio::ip::tcp::endpoint&) {
                if (!ec) {
                    boost::asio::spawn(io_context,
                        [&](boost::asio::yield_context yield) {
                            async_read(socket, yield);
                        });
                }
            });
        // цикл обработки событий, который запускает асинхронные операции и корутины
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}