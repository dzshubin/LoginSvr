#ifndef DBSVRHANDLER_HPP_INCLUDED
#define DBSVRHANDLER_HPP_INCLUDED

#include "Handler.hpp"
#include "CMsg.hpp"
#include <boost/asio/ip/tcp.hpp>


using namespace std;



class DBSvrHandler :public Handler
{
public:
    DBSvrHandler(boost::asio::ip::tcp::socket);

public:
    virtual void start() override;
    virtual void process_msg(int, string) override;


private:
    void handle_verification(string);

};


void send_to_db (CMsg&);

#endif // DBSVRHANDLER_HPP_INCLUDED
