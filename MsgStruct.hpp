#ifndef MSGSTRUCT_HPP_INCLUDED
#define MSGSTRUCT_HPP_INCLUDED



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



#endif // MSGSTRUCT_HPP_INCLUDED
