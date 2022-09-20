#include <iostream>
using namespace std;
#ifndef DOG_H
#define DOG_H
#include "Mammal.h"
#endif
class Mammal
{
    protected:
        string name;
        string sound;
        string action;
    public:
        Mammal(string n = "")
        {
            name = n;
        }

        string getName()
        {
            return name;
        }

        virtual void setName() = 0;

        virtual void doAction() = 0;

        virtual void Speak() = 0;
};