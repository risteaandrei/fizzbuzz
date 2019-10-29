#include <iostream>
#include <string>

#include <boost/asio.hpp>

void run_client(std::string_view host, short const port) {
    try {
        boost::asio::io_service service;
        boost::asio::ip::tcp::socket tcp_socket(service);
        boost::asio::ip::tcp::resolver resolver(service);
        boost::asio::connect(tcp_socket,
                             resolver.resolve({host.data(), std::to_string(port)}));
        
        while (true) {
            std::cout << "number [1-99]: ";
            int number;
            std::cin >> number;
            if (std::cin.fail() || number < 1 || number > 99) {
                break;
            }

            auto request = std::to_string(number);
            tcp_socket.write_some(boost::asio::buffer(request, request.length()));

            std::array<char, 1024> reply;
            auto reply_length = tcp_socket.read_some(
                boost::asio::buffer(reply, reply.size()));

            std::cout << "reply is: ";
            std::cout.write(reply.data(), reply_length);
            std::cout << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}

int main() {
    run_client("172.17.0.2", 11234);
}
