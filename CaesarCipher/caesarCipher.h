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

#include <iostream>
using namespace std;

class caesarCipher {
private:
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
				if (s[i]+shiftValue > 122){ 
					s[i]=122-(s[i]%97);	
				}
				else{
					s[i]+=shiftValue;
				}		
			}
		}
		return s;
    	}

	string decrypt(string s){ 
		for(int i=0;i<s.length();i++){
			if (s[i] >= 97 && s[i] <= 122){
				if (s[i]-shiftValue < 97){
					s[i]=97+(122%s[i]);
				}			
				else{
					s[i]-=shiftValue;		
				}		
			}
		}
		return s;
	}	

	void print(){
		cout << shiftValue << endl;
		return;
     }
};