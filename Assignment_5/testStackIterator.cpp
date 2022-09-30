#ifndef TESTPROG_H
#define TESTPROG_H
#include "myStack.h"
#include <iostream>
using namespace std;

int const MAX_SIZE = 50;
int main()
{
    stackType<int> stack1;
    stackType<int> stackTemp;
    int num;

    stack1.initializeStack();
    cout << "Input numbers, when done enter -999: " << endl;
    cin >> num;

    while(num != -999)
    {
        stack1.push(num);
        cin >> num;
    }

    stackTemp = stack1;
    //testing stack functionality
    cout << "printing stack: " << endl;
    while(!stackTemp.isEmptyStack())
    {
        cout << stackTemp.top() << endl;
        stackTemp.pop();
    }    

    cout << "Iteration through stack: " << endl;
    StackIterator<int> it(stack1.getList(), 0);
    for(it = stack1.getTop(); it != -1; ++ it)
    {
        cout << *it << endl;
    }
    
    return 0;
}

#endif

