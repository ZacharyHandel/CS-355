#include <iostream>
#include "QuickSort.h"

using namespace std;

int main()
{
    QuickSort qs1;

    cout << "BEFORE SORT: " << endl;
    qs1.print(); 
    qs1.quickSort();

    cout << endl << "AFTER SORT:" << endl;
    qs1.print();
    
}