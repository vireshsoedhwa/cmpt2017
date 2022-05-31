#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;


// CMPT 471 A3 part 2:
// RIP Example with 6 routers 7 networks.

class Router{
    public:
        Router();
        int id;
        string name;

        //the array index is the Network Destination
        //the data held inside that index is the number or hops required.
        int *dest_network;
        string *next_hop;
        int *num_of_hops;

        void printRoutingTable();
        void addNetwork(int x);

        ~Router();
};


//constructor
Router::Router(){
    this->name = "nameless";
    this->dest_network = new int[8];
    this->next_hop = new string[8];
    this->num_of_hops = new int[8];

    for(int i = 0; i<8; i++){
        this->dest_network[i] = -1;
    }
}


//destructor
Router::~Router(){
    delete[] dest_network;
    delete[] next_hop;
    delete[] num_of_hops;
}


void Router::printRoutingTable(){

    cout << this->name << " Routing Table:" <<endl;
    cout << "Destination    |  Next Hop  |  Number of Hops"<<endl;
    for(int i=1; i<8; i++){
        cout <<setw(10)<<"N"<<i<<" "<<this->dest_network[i] << " | "<< setw(10)<<this->next_hop[i] << " | "<<setw(10)<<setw(10)<< this->num_of_hops[i]<<endl;
    }

}

void Router::addNetwork(int x){
    this->dest_network[x] = 0;
    this->next_hop[x] = "* direct";
    this->num_of_hops[x] = 0;
}


void changeNameTo(Router &r, string newName){
    r.name = newName;

}

string intToStr(int x){

    stringstream convert_to_string;

    convert_to_string << x;
    return convert_to_string.str();
}


void RIP(Router &from, Router &to){
    cout<<endl;
    cout<<"======== RIP from Router: " << from.name << " to Router: " << to.name <<"========="<< endl;
    from.printRoutingTable();
    to.printRoutingTable();

    ///do the matching and testing

    for(int i=1; i<8; i++){

        //if there is something from
        if(from.dest_network[i] != -1){

            //to is -1 or more hops.
            if((to.dest_network[i] > from.dest_network[i]) || (to.dest_network[i] == -1)){

                //set to hops to from +1 and from's name on next hop
                to.dest_network[i] = from.dest_network[i]+1;
                to.next_hop[i] = from.name;
                to.num_of_hops[i] = from.dest_network[i]+1;

            }
        }
    }




    cout<<endl;
    cout<< "------ Resulting routing table ------"<<endl;
    to.printRoutingTable();
    cout<< "================================================="<<endl;
}




int main(){

    //Making an array of 7 routers, but only 1 - 6 will be used.
    //Router0 will not be used.

    Router *arrayOfRouters;

    arrayOfRouters = new Router[7];


    //Starting routers 1 - 6
    for(int i = 1; i <= 6; i++){
        arrayOfRouters[i].name = "Router#" + intToStr(i);;
        arrayOfRouters[i].addNetwork(i);
        arrayOfRouters[i].addNetwork(i+1);
        arrayOfRouters[i].printRoutingTable();

    }



    // Performing RIP on routers and neighbough routers.
    for(int y = 1; y < 6; y++){
    cout<<endl;
    cout<<"***********************************************************************"<<endl;
    cout<<"**********************STARTING "<<intToStr(y) <<"ND ROUND*******************"<<endl;
    cout<<"***********************************************************************"<<endl;

    //RIP r1
    RIP(arrayOfRouters[1], arrayOfRouters[2]);

    //RIP r2
    RIP(arrayOfRouters[2], arrayOfRouters[1]);
    RIP(arrayOfRouters[2], arrayOfRouters[3]);

    //RIP r3
    RIP(arrayOfRouters[3], arrayOfRouters[2]);
    RIP(arrayOfRouters[3], arrayOfRouters[4]);

    //RIP r4
    RIP(arrayOfRouters[4], arrayOfRouters[3]);
    RIP(arrayOfRouters[4], arrayOfRouters[5]);

    //RIP r5
    RIP(arrayOfRouters[5], arrayOfRouters[4]);
    RIP(arrayOfRouters[5], arrayOfRouters[6]);

    //RIP r6
    RIP(arrayOfRouters[6], arrayOfRouters[5]);


    }




    //output final table
    cout<<endl;
    cout<<"***********************************************************************"<<endl;
    cout<<"**********************FINAL TABLES*******************"<<endl;
    cout<<"***********************************************************************"<<endl;

    for(int j=1; j<=6; j++){

        arrayOfRouters[j].printRoutingTable();

    }






    return 0;
}
