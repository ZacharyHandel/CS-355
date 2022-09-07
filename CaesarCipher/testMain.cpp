#include<iostream>
#include "caesarCipher.h"
using namespace std;

int main()
{
    //class object declaration
    caesarCipher c;

    //creating variables
    string value;

    //test main
    cout << "Input a string: " << endl;
    cin >> value;
    string encryptedValue = c.encrypt(value);

    cout << "Testing Encryption: " << encryptedValue << endl;
    cout << "Testing Decryption: " << c.decrypt(encryptedValue) << endl;

    cout << "Testing Print Function: " << endl;
    c.print();
    return 0;
}