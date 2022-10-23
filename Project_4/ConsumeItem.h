#ifndef CONSUME_H
#define CONSUME_H
#include "Item.h"
#endif

using namespace std;

class ConsumeItem : public Item
{
    private:
        vector<Effect*> effectVec;
    public:
        ConsumeItem()
        {
            type = "consume";
        }
        void setActiveMessage(string s)
        {
            activeMessage = s;
        }

        string getActiveMessage()
        {
            return activeMessage;
        }

        vector<Effect*> getItemConsumeEffects()
        {
            return effectVec;
        }

        void setActiveArea(int a)
        {
            activeArea = a;
        }

        int getActiveArea()
        {
            return activeArea;
        }

        void addEffect(Effect* temp)
        {
            effectVec.push_back(temp);
            
        }
};