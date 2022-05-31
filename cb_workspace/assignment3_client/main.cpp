#include <iostream>
#include <client.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{

    //run this client program with the ip address of the server:
    //assignment3_client x.x.x.x

    //client class created;
    client *theclient = new client();
    theclient->setportnumber(3000); //set port number
    theclient->opensocket();    //socket is opened
    theclient->setserverip(argv[1]); //set serverip from command line
    theclient->initclient(); //initialize and create connection
    theclient->clientconnect(); //

    //client keeps sending messages in a loop every 5 seconds
    //client waits for response message from server

    while(true)
    {
        theclient->sendmessage();
        theclient->getresponsefromserver();
        sleep(5);
    }

    return 0;
}
