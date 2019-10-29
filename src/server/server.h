#ifndef SERVER_H
#define SERVER_H

#include "session.h"

class server {
public:
    server(boost::asio::io_service& service, short const port);

private:
    void accept();

    boost::asio::ip::tcp::acceptor tcp_acceptor;
    boost::asio::ip::tcp::socket tcp_socket;
};

#endif // SERVER_H
