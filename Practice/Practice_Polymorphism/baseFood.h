#include <iostream>
#include <string>
using namespace std;

class baseFood
{
    protected: 
        string description;
        int calories;
    public:
        baseFood(string d = "", int c = 0)
        {
            description = d;
            calories = c;
        }

        virtual void print() = 0;
};