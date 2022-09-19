/*
Name- Zachary Handel
Assignment- Assignment 3
Due Date-
Description- 
*/
#include<iostream>
#include "advancedCaesar.h"
using namespace std;

int main()
{
    advancedCaesar c1;

    string input;
    string input2;
    string encryptedInput;
    string encryptedInput2;
    cout << "Input a word to encrypt: ";
    cin >> input;

    //testing encryption
    encryptedInput = c1.encrypt(input);

    cout << "Current shift value and alphabet: ";
    c1.print();
    cout << "printing encrypted message: " << encryptedInput << endl;

    //testing decryption
    cout << "printing decrypted messsage: " << c1.decrypt(encryptedInput);

    //testing constructor
    cout << "Testing Constructor: " << endl;
    advancedCaesar c2(4);

    cout << "Input a word to encrypt: ";
    cin >> input2;

    //testing encryption w/ new shift value
    encryptedInput2 = c2.encrypt(input2);

    cout << "Current shift value and alphabet: ";
    c2.print();
    cout << "printing encrypted message: " << encryptedInput2 << endl;

    //testing decryption with new shift value
    cout << "printing decrypted messsage: " << c2.decrypt(encryptedInput2);
    



    return 0;
}



//********** TEST CODE! IGNORE******************
    //class object declaration
    //caesarCipher c;

    //creating variables
   // string value;

    //test main
   // cout << "Input a string: " << endl;
   // cin >> value;
   // string encryptedValue = c.encrypt(value);

   // cout << "Testing Encryption: " << encryptedValue << endl;
   // cout << "Testing Decryption: " << c.decrypt(encryptedValue) << endl;

   // cout << "Testing Print Function: " << endl;
  //  c.print();
   // return 0;