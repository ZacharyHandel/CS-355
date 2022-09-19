#include <iostream>
#include <string>
#ifndef PET_T
#define PET_T
#include "petType.h"
#endif
using namespace std;

class catType : public petType
{
    private:
        bool claw;
    public:
        catType(string name = "", bool c = true) : petType(name)
        {
            claw = c;
        }

        void print()
        {
            cout << "Name: " << name << endl;
            if(claw)
            {
                cout << "Has claws" << endl;
            }
            else
            {
                cout << "is de-clawed" << endl;
            }
        }

};
