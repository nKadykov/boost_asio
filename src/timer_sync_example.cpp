#include <iostream>
#include <boost/asio.hpp>

int main() {
    // объект управления операциями ввода-вывода
    boost::asio::io_context io;
    // высокоточный таймер для управления объектом io_context
    boost::asio::steady_timer timer(io);
    // установка времени ожидания в 5 секунд
    timer.expires_after(std::chrono::seconds(5));
    std::cout << "Timer is on, whaiting 5 seconds..." << std::endl;
    // синхронное ожидание
    timer.wait();
    std::cout << "Timer is off" << std::endl;
    
    return 0;
}