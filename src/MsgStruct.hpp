#ifndef MSGSTRUCT_HPP_INCLUDED
#define MSGSTRUCT_HPP_INCLUDED

#include <string>


struct Msg_login
{

    int64_t m_nId;
    std::string m_passwd;


    Msg_login (): m_nId(0)
    {

    }

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & m_nId;
        ar & m_passwd;
    }
};

struct Msg_msgsvr_register
{
    Msg_msgsvr_register () :m_port (0)
    {

    }

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & m_port;
    }

    int m_port;   // 监听的端口
};


struct Msg_msgsvr_allocate
{
    Msg_msgsvr_allocate () :m_port (0)
    {

    }

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & m_port;
    }

    int m_port;   // 分配的服务器的端口
};


struct Msg_update_count
{
    Msg_update_count() :m_user_count(0)
    {

    }

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & m_user_count;
    }

    int m_user_count;
};

struct Msg_validate_result
{
    Msg_validate_result (): m_bResult(false), m_nUserId(0)
    {
    }

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
    	ar & m_bResult;
    	ar & m_nUserId;
    }


    bool m_bResult;
    uint64_t m_nUserId;
};




#endif // MSGSTRUCT_HPP_INCLUDED
