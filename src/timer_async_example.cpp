#include <iostream>
#include <boost/asio.hpp>

void timerHandler(const boost::system::error_code& error) {
    if(!error) {
        std::cout << "Timer is off" << std::endl;
    } else {
        std::cerr << "Error: " << error.message() << std::endl;
    }
}

int main() {
    // объект управления операциями ввода/вывода
    boost::asio::io_context io;
    // объект таймера
    boost::asio::steady_timer timer(io);
    // установка таймера ожидания в 5 секунд
    timer.expires_after(std::chrono::seconds(5));
    // метоо, принимающий callback-функцию, которая будет вызвана по истечении времени ожидания
    timer.async_wait(&timerHandler);
    std::cout << "Timer is on, waiting 5 seconds" << std::endl;
    // запуск цикла обработки событий io_context, который обрабатывает все асинхронные операции до тех пор, пока они не будут завершены
    io.run();
    return 0;
}