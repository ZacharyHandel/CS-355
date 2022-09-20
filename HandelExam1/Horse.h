#ifndef DOG_H
#define DOG_H
#include "Mammal.h"
#endif

class Horse : public Mammal
{
    private:
    //No unique members
    public:
        Horse(string n = "", string so = "nay!", string ac = "gallop") : Mammal(n)
        {   
            name = n;
            sound = so;
            action = ac;
        }

         void setName()
        {
            cout << "NoNameHorse created" << endl; 
            cout << "What is the name of your horse?" << endl;
            cin >> name;
        }
        
        void Speak()
        {
            cout << "The horse named " << name << " says " << sound << endl;
        }

        void doAction()
        {
            cout << "The horse named " << name << " goes " << action << endl;
        }
};
