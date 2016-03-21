#ifndef DbSvrConnection_HPP_INCLUDED
#define DbSvrConnection_HPP_INCLUDED

#include "Connection.hpp"
#include "CMsg.hpp"
#include <boost/asio/ip/tcp.hpp>


using namespace std;



class DbSvrConnection: public Connection
{
public:
    DbSvrConnection(io_service&);

public:
    virtual void start() override;
    virtual void process_msg(int, string) override;

    virtual void stop_after() override;

private:
    void handle_verification(string);

};


void send_to_db (CMsg&);

#endif // DbSvrConnection_HPP_INCLUDED
