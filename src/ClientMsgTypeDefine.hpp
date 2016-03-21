#ifndef CLIENTMSGTYPEDEFINE_HPP_INCLUDED
#define CLIENTMSGTYPEDEFINE_HPP_INCLUDED


//
//

/*
 * 客户端发给服务器的消息类型编号
 * 服务器返回给客户端的消息编号一致
 *
 * 注释格式:
 * 消息用途
 * @parm    客户端请求的消息参数_: 参数意思
 * @return  服务器返回的消息参数 : 参数意思
 */


enum class M2L
{
    REGISTER                            = 7000,
    // 更新当前消息服务器总人数
    UPDATE_SVR_COUNT                    = 7001,
};


/*
 * 客户端与loginsvr的消息定义
 */

enum class C2L
{
    /*
     *      用户登陆
     *
     * @parm    id  : 用户登陆id
     * @return  port: 分配的消息服务器监听端口
     */
    USER_LOGIN                       = 1000,
};


enum class L2D
{
    /*
     *      账号验证
     * @parm    id      : 用户账号
     * @parm    passwd  : 登陆密码
     * @return  result  : 验证结果
     */
     VERIFICATION                   = 3000,

};


#endif // CLIENTMSGTYPEDEFINE_HPP_INCLUDED
