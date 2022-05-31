#include <iostream>
#include <router.h>
#include <advertisement.h>

#define LOG(x) std::cout << "LOG: " << x << std::endl;

int main()
{
    srand (1);

    std::vector<router> routerlist;

    for( int i = 1 ; i <= 7; i++)
    {
        router newrouter(i);
        routerlist.push_back(newrouter);
    }


//sort it
for( int i = 0 ; i <= 6; i++)
{
    routerlist[i].sortroutingtable();
}



std::cout<< " =======BEFORE UPDATE======== " << std::endl;

    for( int i = 0 ; i <= 6; i++)
    {
        routerlist[i].showtable();
    }
//     main loop for RIP

    for(int i = 1 ; i <= 1; i++)
    {
        for (auto RouterItemAd : routerlist)
        {
            advertisement advert;
            advert.from = RouterItemAd.getroutername();
            advert.advertable = RouterItemAd.routingtable;
            LOG(advert.from);



        }
    }









//    advertisement.routingtable.push_back()

    std::cout<< " =======AFTER UPDATE======== " << std::endl;

    for( int i = 0 ; i <= 6; i++)
    {
       routerlist[i].showtable();
    }

    std::cout<< " =============== " << std::endl;





    return 0;
}
