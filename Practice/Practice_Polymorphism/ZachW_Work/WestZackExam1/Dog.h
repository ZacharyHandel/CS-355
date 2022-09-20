#ifndef DOG_H
#define DOG_H




#include "Mammal.h"
#include <iostream>

using namespace std;

class Dog : public Mammal
{
public: 
	Dog()	//right here is where you want to do Dog(string n = "", string so = "bark!bark!", string ac = "lick") : Mammal(name). This is where you set all of the default values and then take the "name" form the abstract base class of Mammal
	{
		cout << "What is the name of your dog? " << endl;
		//right here you just want to go:
		/*
		name = n;
		sound = so;
		action = ac;	It sets all of the default values and then you can change 'name' in the set name
		*/
	}
	void setName(string n)	//looks good
	{
		name = n;
		/*
			cout << "NoNameDog created" << endl; 
            cout << "What is the name of your dog?" << endl;
            cin >> name;	//here is what I did for the setName member
		*/
	}

	void doAction()
	{
		cout << "The dog named" << name << "goes gallop" << endl;	//lick
		//you could also say cout << "The dog named" << name << goes << action << endl;
	}

	void speak()
	{
		cout << "The dog named" << name << "says bark! bark!" << endl;
		//same here, just go 
		//cout << "The dog named " << name << "says " << sound << endl;
	}
};
#endif


//Just apply all of these things to the rest of the derived classes and you should be good to go!
