#include <iostream>
#include <boost/asio.hpp>

void session(boost::asio::ip::tcp::socket socket) {
    try {
        for(;;) {
            char data[1024];
            boost::system::error_code error;
            size_t length = socket.read_some(boost::asio::buffer(data), error);

            if(error == boost::asio::error::eof)
                break;
            else if(error)
                throw boost::system::system_error(error);
            // функция отправки сообщения клиенту
            boost::asio::write(socket, boost::asio::buffer(data, length));
        }
    }
    catch(std::exception& e) {
        std::cerr << "Exception in thread: " << e.what() << '\n';
    }
}

int main() {
    using boost::asio::ip::tcp;
    try {
        // объект управления асинхронными операциями ввода-вывода
        boost::asio::io_context io_context;
        // объект принятия входящих соединений, настроенный для прослушивания всех IP-адресов по порту 12345
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));
        for(;;) {
            // объект для общения с клиентом
            tcp::socket socket(io_context);
            // метод блокирования выполнения до тех пор, пока не будет принято новое соединение
            acceptor.accept(socket);
            std::thread(session, std::move(socket)).detach();
        }
    }
    catch(std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}