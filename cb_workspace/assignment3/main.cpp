#include <iostream>
#include <server.h>

using String = std::string;

int main()
{
     while(true)
     {
        server *serv = new server();
        serv->opensocket();
        serv->setportno(3000);
        serv->initsocket();

        serv->listening();
        serv->readmessage();

        delete serv;
     }

    return 0;
}
