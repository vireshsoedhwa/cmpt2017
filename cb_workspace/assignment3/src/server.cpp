#include "server.h"
#include <iostream>

#define LOG(x) std::cout << "LOG: " << x << std::endl;

using String = std::string;

server::server()
{
    //ctor
}


void server::opensocket()
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

void server::setportno(int inputport)
{
    portno = inputport;
    LOG("port set");
}

void server::initsocket()
{
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
    }
    else
    {
        LOG("socket initialized")
    }
}

void server::listening()
{
    listen(sockfd,5); //firstsocket, backlog
    clilen = sizeof(cli_addr);

    LOG("Waiting for connections");

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0)
      perror("ERROR on accept");
}

void server::readmessage()
{
    bzero(buffer,256);
    int n = read(newsockfd,buffer,255);
    if (n < 0) perror("ERROR reading from socket");
    std::cout << "Here is the message: " << buffer << std::endl;
    n = write(newsockfd,"I got your message",18);
    if (n < 0) perror("ERROR writing to socket");
}

server::~server()
{
     close(newsockfd);
     close(sockfd);
}
