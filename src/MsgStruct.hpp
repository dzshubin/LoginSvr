#ifndef MSGSTRUCT_HPP_INCLUDED
#define MSGSTRUCT_HPP_INCLUDED

#include <string>


struct MSG_LOGIN
{

    int64_t m_nId;
    std::string m_passwd;

    MSG_LOGIN (): m_nId(0)
    {

    }

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & m_nId;
        ar & m_passwd;
    }
};

struct MSG_REGISTER_SVR
{
    MSG_REGISTER_SVR () :m_port (0)
    {

    }

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & m_port;
    }

    int m_port;   // 监听的端口
};


struct MSG_ALLOCATE_PORT
{
    MSG_ALLOCATE_PORT () :m_port (0)
    {

    }

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & m_port;
    }

    int m_port;   // 分配的服务器的端口
};


struct MSG_UPDATE
{
    MSG_UPDATE() :m_user_count(0)
    {

    }

    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & m_user_count;
    }

    int m_user_count;
};

struct MSG_VALIDATE_RESULT
{
    MSG_VALIDATE_RESULT (): m_bResult(false), m_nUserId(0)
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
