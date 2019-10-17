#ifndef SESSION_H
#define SESSION_H

//#define ASIO_STANDALONE
#include <boost/asio.hpp>

class session: public std::enable_shared_from_this<session> {
public:
    session(boost::asio::ip::tcp::socket socket): tcp_socket(std::move(socket)) {}

    void start();

private:
    void read();
    void write(std::string_view response);
    static std::string fizzbuzz(int const number);

    std::array<char, 1024> data;
    boost::asio::ip::tcp::socket tcp_socket;
};

#endif // SESSION_H
