#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "baseFood.h"
#endif
class Sandwich : public baseFood
{
    private:
        string bread;
    public:
        Sandwich(string b = "") : baseFood(description, calories)
        {
            bread = b;
        }

        void print()
        {
            cout << description << endl;
            cout << calories << endl;
            cout << bread << endl;
        }
};