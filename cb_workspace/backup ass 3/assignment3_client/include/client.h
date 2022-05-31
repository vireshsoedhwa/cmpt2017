#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

using String = std::string;

class client
{
    private:
        int sockfd, portnumber, sockethandle;
        struct sockaddr_in serv_addr;
        struct hostent *server;
        char buffer[1000];

        int messagecount;

        String messagetosend();

    public:
        client();
        void setportnumber(int inputport);
        void opensocket();
        void setserverip(const char*);
        void initclient();
        void clientconnect();

        void sendmessage();

        void getresponsefromserver();

        virtual ~client();

    protected:


};

#endif // CLIENT_H
