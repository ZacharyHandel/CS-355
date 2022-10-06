#ifndef CONSUME_H
#define CONSUME_H
#include "Item.h"
#endif

using namespace std;

class UseItem : public Item
{
    public:
        void setActiveMessage(string s)
        {
            activeMessage = s;
        }

        string getActiveMessage()
        {
            return activeMessage;
        }

        void setActiveArea(int a)
        {
            activeArea = a;
        }

        int getActiveArea()
        {
            return activeArea;
        }
    private:
        
};