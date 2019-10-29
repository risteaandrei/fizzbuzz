#include "server.h"

#include <iostream>

server::server(boost::asio::io_service& service, short const port)
    : tcp_acceptor(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
    , tcp_socket(service)
{
    std::cout << "server running on port " << port << std::endl;
    accept();
}

void server::accept() {
    tcp_acceptor.async_accept(tcp_socket, [this](std::error_code ec) {
        if (!ec) {
            std::make_shared<session>(std::move(tcp_socket))->start();
        }
        accept();
    });
}
