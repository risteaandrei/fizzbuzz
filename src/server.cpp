#define ASIO_STANDALONE
#include <asio.hpp>

class session: public std::enable_shared_from_this<session> {
public:
    session(asio::ip::tcp::socket socket): tcp_socket(std::move(socket)) {}
    
    void start() {
        read();
    }

private:
    void read() {
        auto self(shared_from_this());

        tcp_socket.async_read_some(
            asio::buffer(data, data.size()),
            [this, self](std::error_code const ec, std::size_t const length) {
                if (!ec) {
                    auto number = std::string(data.data(), length);
                    auto rezult = fizzbuzz(std::atoi(number.c_str()));
                    std::cout << number << "->" << resutl << std::endl;
                    write(result);
                }
            }
        );
    }

    void write(std::string_view response) {
        auto self(shared_from_this());

        tcp_socket.async_write_some(
            asio::buffer(response.data(), response.length)),
            [this, self](std::error_code const ec, std::size_t const) {
                if (!ec) {
                    read();
                }
            }
        );
    }

    std::array<char, 1024> data;
    asio:ip:tcp::socket tcp_socket;
}