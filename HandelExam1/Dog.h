#ifndef DOG_H
#define DOG_H
#include "Mammal.h"
#endif

class Dog : public Mammal
{
    private:
    //No new unique members
        
    public:
        Dog(string name = "", string so = "bark!bark!", string ac= "lick lick") : Mammal(name)
        {
            name = name;
            sound = so;
            action = ac;
        }

        void setName()
        {
            cout << "NoNameDog created" << endl; 
            cout << "What is the name of your dog?" << endl;
            cin >> name;
        }
        
        void Speak()
        {
            cout << "The dog named " << name << " says " << sound << endl;
        }

        void doAction()
        {
            cout << "The dog named " << name << " goes " << action << endl;
        }
};






