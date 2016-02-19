#ifndef CMSGSVR_HPP_INCLUDED
#define CMSGSVR_HPP_INCLUDED



class CMsgSvr
{
public:
    CMsgSvr (void *context_, int port_);


    int get_port();

    void set_user_count(int);
    int get_user_count();

    void *get_context();

    // 自定义比较
    bool operator<(CMsgSvr&);

private:
    // 上下文
    void* m_context;
    // 服务器监听端口
    int m_port;
    // 该服务器总人数
    int m_user_count;
};


#endif // CMSGSVR_HPP_INCLUDED
