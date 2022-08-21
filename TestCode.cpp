#include <iostream>
using namespace std;

int main()
{
    string name;
    int favNum;
    cout << "Hello! What is your name?" << endl;
    cin >> name;
    cout << "Hello, " << name << endl;
    
    cout << "What is your favorite number? I will add 3 to it!" << endl;
    cin >> favNum;
    favNum += 3;
    cout << "the new number is now " << favNum << endl;

    return 0;
}