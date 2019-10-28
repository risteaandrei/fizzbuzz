#include "server.h"
#include <iostream>

void run_server(short const port) {
    try {
        boost::asio::io_service service;
        server src(service, port);
        service.run();
    } catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}

int main() {
    run_server(11234);
}