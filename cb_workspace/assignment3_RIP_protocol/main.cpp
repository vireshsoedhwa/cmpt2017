#include <iostream>
#include <string>

#define LOG(x) std::cout << "LOG: " << x << std::endl;

using String = std::string;

class Router{
    public:
        Router()
        {
            Dest = new int[8];
            next_hop = new int[8];
            hop_count = new int[8];
            Name = 0;

            for(int i = 0; i<8; i++)
            {
                Dest[i] = -1;//set unreachable flag
            }
        }
        virtual ~Router();
        int Name, *next_hop, *hop_count, *Dest;
        void showtable()
        {
            std::cout <<"Router : R" << Name << std::endl;
            std::cout << "Dest Net || " << "Next hop || " << " Hop count" << std::endl;
            for(int i=1; i<=7; i++)
            {
                std::cout <<"N" << i << "    " << "     ";
                std::cout << "R" << next_hop[i] + 1 << "      ";
                std::cout << hop_count[i] + 1 << std::endl;
            }
        }
        void AddnextNeighbour(int nextneighbour)
        {
            Dest[nextneighbour] = 0;
            next_hop[nextneighbour] = 0;
            hop_count[nextneighbour] = 0;
        }
};

Router::~Router(){
    //dtor
}

void perform_RIP(Router &Advertiser, Router &Receiver){

    for(int i=1; i<=7; i++){

        //Only send advertising to neighbours
        if(Advertiser.Dest[i] != -1)
        {
            //compare advertisement list with current router  table
            if(Advertiser.Dest[i] < (Receiver.Dest[i]) ||
             (Receiver.Dest[i] == -1)){

                //update receiver router table values.
                Receiver.Dest[i] = Advertiser.Dest[i]+1;
                Receiver.next_hop[i] = Advertiser.Name;
                Receiver.hop_count[i] = Advertiser.Dest[i]+1;
            }
        }
    }

    String Advertisermsg = "Advertiser Router R" + std::to_string(Advertiser.Name) + " ";
    LOG(Advertisermsg);
    Advertiser.showtable();
    String Receivermsg = "Receiver Router R" + std::to_string(Receiver.Name);
    LOG(Receivermsg);
    Receiver.showtable();


    LOG(" Receiver table values after advertisement ");
    Receiver.showtable();
    std::cout<< " -------- "<< std::endl;
}

int main(){

    //create new list of routers
    Router *routerlist = new Router[7];

    //initialize list with neighbour connections.
    for(int i = 1; i < 7; i++){
        routerlist[i].Name = i;
        routerlist[i].AddnextNeighbour(i);
        routerlist[i].AddnextNeighbour(i+1);
        routerlist[i].showtable();
    }


    //Perform RIP 7 times on all routers and their connections to neighbours
    for(int i = 1; i < 7; i++){

        String message = "Round " + std::to_string(i);
        message += "--------------------------------------------------------";

        LOG(message)

        //all routers except the first and last have two neighbour connections.
        //perform RIP in the following order.
        //R1>>R2>>R3>>R4>>R5>>R6>>R7

        //R1
        perform_RIP(routerlist[1],routerlist[2]);

        //R2
        perform_RIP(routerlist[2],routerlist[1]);
        perform_RIP(routerlist[2],routerlist[3]);

        //R3
        perform_RIP(routerlist[3],routerlist[2]);
        perform_RIP(routerlist[3],routerlist[4]);

        //R4
        perform_RIP(routerlist[4],routerlist[3]);
        perform_RIP(routerlist[4],routerlist[5]);

        //R5
        perform_RIP(routerlist[5],routerlist[4]);
        perform_RIP(routerlist[5],routerlist[6]);

        //R6
        perform_RIP(routerlist[6],routerlist[5]);

    }

    LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    LOG("Updated Routertables: ");

    for(int j=1; j<=6; j++)
    {
        routerlist[j].showtable();
    }


    return 0;
}
