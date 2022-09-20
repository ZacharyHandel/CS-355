#ifndef DOG_H
#define DOG_H
#include "Mammal.h"
#endif
class Cat : public Mammal
{
    private:
    //No unique members
    public:
        Cat(string n = "", string so = "meow!", string ac = "preen") : Mammal(n)
        {   
            name = n;
            sound = so;
            action = ac;
        }

         void setName()
        {
            cout << "NoNameCat created" << endl; 
            cout << "What is the name of your cat?" << endl;
            cin >> name;
        }
        
        void Speak()
        {
            cout << "The cat named " << name << " says " << sound << endl;
        }

        void doAction()
        {
            cout << "The cat named " << name << " goes " << action << endl;
        }
};