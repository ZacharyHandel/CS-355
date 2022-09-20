#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "baseFood.h"
#endif

#include "Pizza.h"
#include "Sandwich.h"
using namespace std;

void callPrint(baseFood& f);


int main()
{
    Pizza p1("Pizza",750,"Marinara",14);
    Sandwich s1;
    p1.print();
    callPrint(p1);

}

void callPrint(baseFood& f)
{
    f.print();
}