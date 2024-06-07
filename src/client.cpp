#include "game_client.h"
#include <iostream>
#include <thread>

int main(int argc, char* argv[]) {
    try {
        if(argc != 3) {
            std::cerr << "Usage: client <host> <post>\n";
            return 1;
        }

        boost::asio::io_context io_context;
        GameClient client(io_context, argv[1], argv[2]);

        std::thread t([&io_context]() {
            io_context.run();
        });
        std::string line;
        while(std::getline(std::cin, line)) {
            client.write(line + "\n");
        }

        client.close();
        t.join();
    } catch(std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << "\n";
    }

    return 0;
}