#include "LoginUser.hpp"

LoginUser::LoginUser()
{
    //ctor
}

LoginUser::~LoginUser()
{
    //dtor
}


////////////

void LoginUser::set_conn(connection_ptr conn_)
{
    m_conn = conn_;
}

connection_ptr LoginUser::get_conn()
{
    return m_conn;
}

void LoginUser::set_id (int64_t id_)
{
    m_id = id_;
}

int64_t LoginUser::get_id()
{

    return m_id;
}

void LoginUser::free_conn()
{
    m_conn.reset();
}
