#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>

using String = std::string;

struct tableitem{
    int dest_net;
    int next_hop;
    int hop_count;
};


class router
{
    private:
        int routername;

        bool checkifunique(int thedest, std::vector<tableitem> newtable);

        static bool sortinglambda(const tableitem &a, const tableitem &b);

    public:

        std::vector<tableitem> routingtable;
        router(int number);

        void generaterandomtable();
        void setname(int name);
        void showtable();

        void sortroutingtable();
        int getroutername();

        const String avail_dest[7] = {"N1", "N2", "N3", "N4", "N5", "N6", "N7"};
        const String avail_routers[7] = {"R1", "R2", "R3", "R4", "R5", "R6", "R7"};

        virtual ~router();

    protected:

};

#endif // ROUTER_H
