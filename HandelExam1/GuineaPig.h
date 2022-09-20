#ifndef DOG_H
#define DOG_H
#include "Mammal.h"
#endif
class GuineaPig : public Mammal
{
    private:
    //No unique members
    public:
        GuineaPig(string n = "", string so = "weep weep!", string ac = "skitter") : Mammal(n)
        {   
            name = n;
            sound = so;
            action = ac;
        }

         void setName()
        {
            cout << "NoNameGuineaPig created" << endl; 
            cout << "What is the name of your guinea pig?" << endl;
            cin >> name;
        }
        
        void Speak()
        {
            cout << "The guinea pig named " << name << " says " << sound << endl;
        }

        void doAction()
        {
            cout << "The guinea pig named " << name << " goes " << action << endl;
        }
};