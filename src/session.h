#ifndef SESSION_H
#define SESSION_H

#define ASIO_STANDALONE
#include <asio.hpp>

class session: public std::enable_shared_from_this<session> {
public:
    session(asio::ip::tcp::socket socket): tcp_socket(std::move(socket)) {}
    
    void start();

private:
    void read();
    void write(std::string_view response);

    std::array<char, 1024> data;
    asio:ip:tcp::socket tcp_socket;
};

#endif // SESSION_H
