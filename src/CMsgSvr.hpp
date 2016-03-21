#ifndef CMSGSVR_HPP_INCLUDED
#define CMSGSVR_HPP_INCLUDED


#include "Connection.hpp"

class CMsgSvr
{
public:
    CMsgSvr();

    int get_port();
    void set_port(int);

    void set_user_count(int);
    int get_user_count();

    connection_ptr get_conn ();
    void set_conn(connection_ptr);

    void free_conn();

    // 自定义比较
    bool operator<(CMsgSvr&);

private:
    //
    connection_ptr m_conn;
    // 服务器监听端口
    int m_port;
    // 该服务器总人数
    int m_user_count;
};


#endif // CMSGSVR_HPP_INCLUDED
