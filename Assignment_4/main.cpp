/*
Name- Zachary Handel
Assignment- Assignment 5
Due Date- 9/19/2022
Description- This assignment is an exercise to create derived classes from a base class using inheritance and polymorphism.
*/
#include "Increasing.h"
#include "Decreasing.h"
using namespace std;

void callCompare(AbstractSort& a);  //initialize pure virtual function

int main()
{
    Increasing inc;
    Decreasing dec;
    inc.randomFill();
    dec.randomFill();
    cout << "*****DEMONSTRATION OF INCREASING DERIVED CLASS*****" << endl << endl;
    cout << "Before sort: " << endl;
    inc.print();
    inc.sort();
    cout << "After sort: " << endl;
    inc.print();

    cout << endl << "*****DEMONSTRATION OF DECREASING DERIVED CLASS*****" << endl << endl;
    cout << "Before sort: " << endl;
    dec.print();
    dec.sort();
    cout << "After sort: " << endl;
    dec.print();
    return 0;
};

void callCompare(AbstractSort& a)       //not needed??
{
   // a.compare();
}