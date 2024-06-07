#include <iostream>
#include <boost/asio.hpp>

int main() {
    try {
        using boost::asio::ip::tcp;
        // объект io-context асинхронные операции ввода-вывода
        boost::asio::io_context io_context;
        // объект resolver преобразовавыет человеческие читаемые имена хостов в объект, который может быть использован для установления соединения
        tcp::resolver resolver(io_context);
        // метод resolve() преобразует доменное имя и сервис в список конечных точек, которые могут быть использованы для установления соединения
        tcp::resolver::results_type endpoints = resolver.resolve("www.example.com", "http");
        // вывод конечных точек
        for(const auto& endpoint : endpoints) {
            std::cout << endpoint.endpoint() << std::endl;
        }
    } catch(std::exception& e) {
        // вывод сообщений о перехваченных ошибках
        std::cerr << "Exception: " << e.what() << std::endl; 
    }
}