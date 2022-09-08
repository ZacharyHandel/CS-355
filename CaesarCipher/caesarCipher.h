/*
To-Do:
    - create new class called advancedCaesar which
    derives from this class "caesarCipher.h"
        - Single private attribute which has
        an array of characters for storing the cipher
        alphabet (after it has been shifted)
        - Paramaterless Constructor and a constructor
        that accepts a single integer
            - Constructor is responsible for setting
            values of the character array to the 26 letters
            of the alphabet in the order dictated by the shift value
            - Make sure to make use of the inherited constructors
        - Print function that now prints out shift value and cipher
        alphabet
*/

/*
Name- Zachary Handel
Assignment- Assignment 3
Due Date-
Description- 
*/
#include <iostream>
using namespace std;

class caesarCipher {
protected:
	int shiftValue;
		
public:
	caesarCipher(){
	  shiftValue = 1;
	}

	caesarCipher(int sv){
		shiftValue = sv;
	}
		
	string encrypt(string s){ 
		for(int i=0;i<(s.length());i++){
			if (s[i] >= 97 && s[i] <= 122){
				s[i] += shiftValue;
				if (s[i] > 122){ 
					s[i]=((s[i]%122)+97)-1;	
				}
						
			}
			else
			{
				cout << "Only imput lowercase values." << endl;
			}
		}
		return s;
    	}

	string decrypt(string s){ 
		for(int i=0;i<s.length();i++){
			if (s[i] >= 97 && s[i] <= 122){
				s[i]-= shiftValue;
				if (s[i]< 97){
					s[i]=122-(97-s[i]-1);
				}				
			}
			else
			{
				cout << "Only imput lowercase values." << endl;
			}
		}
		return s;
	}	

	void print(){
		cout << shiftValue << endl;
		return;
     }
};