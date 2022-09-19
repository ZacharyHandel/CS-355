#ifndef PET_T
#define PET_T
#include "petType.h"
#endif
class dogType : public petType
{
    public:
        dogType(string n = "", string b = ""):petType(n)
        {
            breed = b;
        }

        void print()    //overriding the function
        {
            //petType::print();   //calls origional print method
            cout << "Name: " << name << endl;
            cout << "Breed: " << breed << endl;
        }
    private:
        string breed;
};