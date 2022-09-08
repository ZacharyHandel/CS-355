#include <iostream>
using namespace std;

#include "FizzBuzzExt.h"

int main()
{
    FizzBuzzExt fizz(100, 150);
    int choice;

    choice = fizz.compPrintMenu();
    while(choice != 5)
    {
        switch(choice)
        {
            case 1:
                cout << endl;
                fizz.run();
                cout << endl;
                break;
            case 2:
                fizz.setLimit();
                break;
            case 3:
                fizz.clear();
                break;
            case 4:
                fizz.addRule();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
        choice = fizz.compPrintMenu();
    }
    return 0;
}