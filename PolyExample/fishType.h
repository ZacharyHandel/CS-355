#include <iostream>
#include <string>

#ifndef PET_T
#define PET_T
#include "petType.h"
#endif
using namespace std;

class fishType : public petType
{
    private:
        string color;
    public:
        fishType(string name = "", string co = "") : petType(name)
        {
            color = co;
        }

        void print()
        {
            cout << "Name: " << name << endl;
            cout << "Color: " << color << endl;
        }
};