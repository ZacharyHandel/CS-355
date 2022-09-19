#ifndef PET_T
#define PET_T
#include <iostream>
#include "petType.h"
#endif

#include "dogType.h"
#include "catType.h"
#include "fishType.h"
using namespace std;

void callPrint(petType& p);

int main()
{
    //petType pT("Dogfood");    cannot be called due to pure virtual type inside petType
    dogType dT("Noodle", "Standard Poodle");

    //pT.print();
    dT.print();
    cout << "***** ABOUT TO CALL FUNCTION *****" << endl << endl;

    //callPrint(pT);
    callPrint(dT);  //DOG TYPE ISSSSSS A PET TYPE

    catType cT("Rufus",true);
    fishType fT("Nemo","Orange");

    callPrint(cT);
    callPrint(fT);

    petType* pTArray[3];
    pTArray[0] = &dT;
    pTArray[1] = &cT;
    pTArray[2] = &fT;

    for(int i = 0; i < 3; i++)
    {
        pTArray[i]->print();
    }
    return 0;
}

void callPrint(petType& p)
{
    p.print();  //always call print from petType even if we call a dogType object
}

//We just created an ADT (we cannot create an instance of this ADT)