#ifndef SESSION_H
#define SESSION_H

#include <random>

#include <boost/asio.hpp>

class session: public std::enable_shared_from_this<session> {
public:
    session(boost::asio::ip::tcp::socket socket):
        tcp_socket(std::move(socket))
        , distribution(5, 10) {}

    void start();

private:
    void read();
    void write(std::string_view response);
    static std::string fizzbuzz(int const number);

    std::array<char, 1024> data;
    boost::asio::ip::tcp::socket tcp_socket;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;
};

#endif // SESSION_H
