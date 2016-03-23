#ifndef LOGINUSER_H
#define LOGINUSER_H


#include "Connection.hpp"

class LoginUser
{
public:
    LoginUser();
    ~LoginUser();


    void set_conn(connection_ptr);
    connection_ptr get_conn();
    void free_conn();

    void set_id (int64_t id_);
    int64_t get_id();

    inline int get_conn_id() { return m_conn_id; }
    void set_conn_id(int conn_id_) { m_conn_id = conn_id_; }

private:
    connection_ptr m_conn;
    int64_t m_id;
    int m_conn_id;
};

#endif // LOGINUSER_H
