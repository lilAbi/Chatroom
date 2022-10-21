#include <iostream>
#include <boost/asio.hpp>
#include <array>

using TCP = boost::asio::ip::tcp;

int main(int argc, char* argv[]){
    boost::asio::io_context ioContext;

    TCP::resolver resolver{ioContext};

    auto endpoints = resolver.resolve("127.0.0.1", "13");

    TCP::socket socket{ioContext};

    boost::asio::connect(socket, endpoints);

    while(true){
        std::array<char, 128> buffer{};
        boost::system::error_code error;

        size_t len = socket.read_some(boost::asio::buffer(buffer), error);
        if(error == boost::asio::error::eof){
            break;
        }

        std::cout.write(buffer.data(), len);
    }


    return 0;
}
