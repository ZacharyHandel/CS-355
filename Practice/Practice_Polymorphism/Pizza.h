#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "baseFood.h"
#endif
class Pizza: public baseFood
{
    private:
        string sauce;
        int size;
    public:
        Pizza(string d = "", int c = 0, string sce = "", int s = 10): baseFood(d, c)
        {
            sauce = sce;
            size = s;
        }

        void print()
        {
            cout << description << endl;
            cout << calories << endl;
            cout << sauce << endl;
            cout << size << endl;
        }
};