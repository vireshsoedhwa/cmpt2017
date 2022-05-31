#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H
#include <vector>
#include <router.h>

class advertisement
{

    public:
        advertisement();
        std::vector<tableitem> advertable;
        void updateadvert(tableitem table);
        virtual ~advertisement();

        int from;

    protected:

    private:
};

#endif // ADVERTISEMENT_H
