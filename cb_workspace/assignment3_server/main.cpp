#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define LOG(x) std::cout << "LOG: " << x << std::endl;

int main()
{
    //Important variables that will be used by socket.
    int sockfd, newsockfd, portno, socketstate;
    socklen_t clilen;
    char buffer[1000];
    struct sockaddr_in serv_addr, cli_addr;


    //test if socket can be opened
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        LOG("ERROR opening socket");
    }
    else
    {
        LOG("socket opened");
    }

    //set the port
    portno = 3000;
    LOG("port set");

    //basic defaults for the socket
    //INADDR_ANY so server can receive from any client. server does not need IP address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    //check if it binds to interface and initialize properly
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
    }
    else
    {
        LOG("socket initialized")
    }

    //the server is now listening for new connections
    listen(sockfd,5); //firstsocket, backlog
    clilen = sizeof(cli_addr);


    //server accepts connection reads messade and goes in a second while loop
    //because the client keeps sending msg every 5 seconds. if the connection is broken
    //"socketstate == 0" then this loops breaks and the server goes back to the
    //first loop and waits for new clients.
    while(true)
    {
        LOG("Waiting for connections");
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
          perror("ERROR on accept");

        while(true)
        {
            LOG("Waiting for client");
            bzero(buffer,1000);
            socketstate = recv(newsockfd, buffer, sizeof(buffer), 0);
            if (socketstate < 0) perror("ERROR reading from socket");

            std::cout << "client message: " << buffer << std::endl;
            std::cout << "message size:  " << socketstate << std::endl;

            if(socketstate == 0)
            {
                break;
            }
            //respond to client
            int n = send(newsockfd, "I got your message", strlen(buffer), 0);
            if (n < 0) perror("ERROR sending to client");
        }

        LOG("client disconnected");
    }




    return 0;
}
