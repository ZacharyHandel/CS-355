#ifndef TESTPROG_H
#define TESTPROG_H
#include "myStack.h"
using namespace std;

int main()
{
    stackType<int> stack1;
    int num;

    stack1.initializeStack();
    cout << "Enter integers. When done, input -999: " << endl;
    cin >> num;

    while(num != -999)
    {
        stack1.push(num);
        cin >> num;
    }

    cout << endl;

    cout << "top element of stack: " << stack1.top() << endl;

    StackIterator<int> it;
    stackType<int> stackC;
    stackC = stack1;
    
    for(it = stack1.top(); !stack1.isEmptyStack(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;


    return 0;  
}

#endif

