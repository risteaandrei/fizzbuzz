#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>

#include <boost/asio.hpp>

class client {
public:
    client(const std::string& host, short const port)
        : host(host)
        , port(port) {}

    void run() const;
private:
    std::string host;
    short port;
};

#endif // CLIENT_H
