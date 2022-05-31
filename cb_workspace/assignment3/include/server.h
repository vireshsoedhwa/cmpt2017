#ifndef SERVER_H
#define SERVER_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class server
{
    private:

    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];

    struct sockaddr_in serv_addr, cli_addr;

    public:
        server();
        void opensocket();
        void setportno(int inputport);
        void initsocket();
        void listening();
        void readmessage();


        virtual ~server();

    protected:

};

#endif // SERVER_H
