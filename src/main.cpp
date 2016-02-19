#include <iostream>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>



#include "ClientHandler.hpp"
#include "Server.hpp"

using namespace std;
using namespace boost::asio;

int main()
{
    io_service io;
    Server s(io, 9800, 9900);
    io.run();
}
