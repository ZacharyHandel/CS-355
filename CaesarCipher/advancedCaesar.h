<<<<<<< HEAD
/*
Name- Zachary Handel
Assignment- Assignment 3
Due Date-
Description- 
*/
=======
>>>>>>> 7282639eb30e59d6f09ad8a20bb38e8758f05e75
#include <iostream>
#include "caesarCipher.h"
using namespace std;

int const MAX_ALPHABET_SIZE = 26;
class advancedCaesar: public caesarCipher
{
    private:
        char cipherAlphabet[MAX_ALPHABET_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    public:
        advancedCaesar()
        {
                shiftValue = 1;

                for(int i = 0; i < MAX_ALPHABET_SIZE; i++)
                {
                    if(cipherAlphabet[i] >= 97 && cipherAlphabet[i] <= 122)
                    {
                        if(cipherAlphabet[i]+shiftValue > 122)
                        {
                            cipherAlphabet[i] = 122 - (cipherAlphabet[i]%97);
                        }
                        else
                        {
                            cipherAlphabet[i] += shiftValue;
                        }
                    }
                }
        }

        advancedCaesar(int value)
        {
            shiftValue = value;

            for(int i = 0; i < MAX_ALPHABET_SIZE; i++)
                {
                    if(cipherAlphabet[i] >= 97 && cipherAlphabet[i] <= 122)
                    {
                        if(cipherAlphabet[i]+shiftValue > 122)
                        {
                            cipherAlphabet[i] = 122 - (cipherAlphabet[i]%97);
                        }
                        else
                        {
                            cipherAlphabet[i] += shiftValue;
                        }
                    }
                }
        }

        void print()
        {
            cout << shiftValue << endl;
            for(int i = 0; i < MAX_ALPHABET_SIZE; i++)
            {
                cout << cipherAlphabet[i] << endl;
            }
        }
};