
#include "Server.hpp"



int main()
{
    g_app = new Server(9800, 9900);
    g_app->initialization();
    g_app->run();


    return 0;
}
