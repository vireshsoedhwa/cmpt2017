#include "router.h"

router::router(int number)
{
    routername = number;
    generaterandomtable();
}


router::~router()
{
    //dtor
}


void router::showtable()
{
    std::cout << "Im router " << routername << std::endl;

    std::cout << "Dest Net | " << "Next hop | " << " Hop count" << std::endl;

    for (auto tableitem : routingtable)
    {
    std::cout << avail_dest[tableitem.dest_net] << "   ";
    std::cout << avail_routers[tableitem.next_hop] << "   ";
    std::cout << tableitem.hop_count<< "   " << std::endl;
    }
}

void router::generaterandomtable()
{
    int tablelength = rand() % 7 + 1;

    std::vector<tableitem> newtable;

    for( int i = 0 ; i < tablelength; i++)
    {
        // destination should be unique
        int randomdest;
        do
        {
            randomdest = rand() % 6 + 0;
        }
        while(!checkifunique(randomdest, newtable));
        int randomhops = rand() % 10 + 1;
        int randomrouter = rand() % 6 + 0;

        tableitem tableitem;

        tableitem.dest_net = randomdest;
        tableitem.hop_count = randomhops;
        tableitem.next_hop = randomrouter;
        newtable.push_back(tableitem);
    }
    routingtable = newtable;
}

void router::sortroutingtable()
{
    std::sort(routingtable.begin(), routingtable.end(), sortinglambda);
}

bool router::checkifunique(int thedest, std::vector<tableitem> newtable)
{
    for (auto tableitem : newtable)
    {
        if(tableitem.dest_net == thedest)
        {
            return false;
        }
    }

    return true;
}

void router::setname(int name)
{
    routername = name;
}

int router::getroutername()
{
    return routername;
}

bool router::sortinglambda(const tableitem &a, const tableitem &b)
{
    return a.dest_net < b.dest_net;
}
