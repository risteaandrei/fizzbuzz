#include "session.h"

#include <iostream>

void session::start() {
    read();
}

void session::read() {
    auto self(shared_from_this());

    tcp_socket.async_read_some(
        boost::asio::buffer(data, data.size()),
        [this, self](std::error_code const ec, std::size_t const length) {
            if (!ec) {
                auto number = std::string(data.data(), length);
                auto result = fizzbuzz(std::atoi(number.c_str()));
                std::cout << number << "->" << result << std::endl;
                write(result);
            }
        }
    );
}

void session::write(std::string_view response) {
    auto self(shared_from_this());

    tcp_socket.async_write_some(
        boost::asio::buffer(response.data(), response.length()),
        [this, self](std::error_code const ec, std::size_t const) {
            if (!ec) {
                read();
            }
        }
    );
}

std::string session::fizzbuzz(int const number) {
    if (number != 0) {
        auto m3 = number % 3;
        auto m5 = number % 5;
        if (m3 == 0 && m5 == 0) {
            return "fizzbuzz";
        } else if (m5 == 0) {
            return "buzz";
        } else if (m3 == 0) {
            return "fizz";
        }

        return std::to_string(number);
    }
}
