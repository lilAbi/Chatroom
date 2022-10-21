#include <iostream>
#include <string>
#include "boost/asio.hpp"
#include "Networking/Utility.h"

using TCP = boost::asio::ip::tcp;

int main(){
    //create a context
    boost::asio::io_context ioContext;

    TCP::acceptor acceptor(ioContext, TCP::endpoint(TCP::v4(), 13));

    while(true){
        TCP::socket socket(ioContext);
        acceptor.accept(socket);
        std::string hello = "Hello, Client";
        boost::system::error_code error;

        boost::asio::write(socket, boost::asio::buffer(hello), error);
    }

    return 0;
}