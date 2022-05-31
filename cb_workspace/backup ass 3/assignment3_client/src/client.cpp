#include "client.h"

#define LOG(x) std::cout << "LOG: " << x << std::endl;

client::client()
{
    messagecount = 0;
}

void client::opensocket()
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        LOG("ERROR opening socket");
    }
    else
    {
        LOG("socket opened");
    }

}

void client::setportnumber(int inputport)
{
    portnumber = inputport;
    LOG("port set");
}

void client::setserverip(const char* ipaddress)
{
    server = gethostbyname(ipaddress);
    if (server == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

}

void client::initclient()
{
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portnumber);
}

void client::clientconnect()
{
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(0);
    }
    else
    {
        LOG("Connected");
    }
}

void client::sendmessage()
{
    bzero(buffer,1000);

    String messagepacket = messagetosend();

    const char *cstr = messagepacket.c_str();

    strcpy(buffer, cstr);

    sockethandle = send(sockfd,buffer,strlen(buffer), 0);
    if (sockethandle < 0)
    {
        perror("ERROR writing to socket");
    }
    else
    {
        LOG("message send");
    }
}

void client::getresponsefromserver()
{
    bzero(buffer,1000);
    sockethandle = recv(sockfd,buffer,999, 0);
    if (sockethandle < 0)
    {
        perror("ERROR reading from socket");
    }
    else
    {
        LOG("Message received by server: ");
        std::cout<<buffer<<std::endl;
    }
}

String client::messagetosend()
{
    messagecount++;
    String msend = "This is message #: ";
    msend += std::to_string(messagecount);
    return msend;
}

client::~client()
{
    close(sockfd);
}
