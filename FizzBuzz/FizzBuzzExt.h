//#include "FizzBuzz.h"
#include <iostream>
using namespace std;
class FizzBuzzExt : public FizzBuzz
{
    private: 
        int* mults;
        string* words;
        int numrules;

    public:
        FizzBuzzExt(int size, int l) : FizzBuzz(l)
        {
            mults = new int[size];
            words = new string[size];
            numrules = 0;
        }

        void clear()
        {
            numrules = 0;
        }

        void addRule()
        {
            int newnum;
            string newword;
            cout << "Enther the new multiple: " << endl;
            cin >> newnum;
            cout << "Enter the new word: " << endl;
            cin >> newword;
            mults[numrules] = newnum;
            words[numrules] = newword;
            numrules++; //change index every time we add a new rule
        }

        int menu()
        {
            int choice;
	        cout << "********Menu********" << endl;
	        cout << "1. Run Game" << endl;
	        cout << "2. Set New Limit Value" << endl;
	        cout << "3. Quit" << endl;
            cout << "Enter your menu option: " << endl;
            cin >> choice;
            return choice;
        }

        void run()
        {
            bool flag;
            if(numrules == 0)
            {
                cout << "Sorry, no rules currently exist" << endl;
                return;
            }
            
            for(int i = 1; i <= limit; i++)
            {
                string output = "";
                flag = false;

                if(i % 3 == 0)
                {
                    output += "Fizz";
                    flag = true;
                }
                if(i % 5 == 0)
                {
                    output += "Buzz";
                    flag = true;
                }
                if(i % 7 == 0)
                {
                    output += "Biff";
                    flag = true;
                }

                for(int j = 0; j < numrules; j++)   //looks for every multiple and add word to output
                {
                    if(i % mults[j] == 0)
                    {
                        output += words[j];
                        flag = true;
                    }
                }
                if(flag)
                {
                    cout << output << endl;
                    flag = false;
                }
                else
                {
                    cout << i << endl;
                }
            }
        }

};
