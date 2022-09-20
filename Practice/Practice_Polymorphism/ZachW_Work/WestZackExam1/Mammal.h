#ifndef MAMMAL_H
#define MAMMAL_H

#include <iostream>

using namespace std; 

class Mammal
{
protected:
	string name; 
	string sound; 
	string aciton; 
public: 
	Mammal()	//No need for this, its already understood
	{

	}

	Mammal(string n) 	//good just set n = "" in the parameters
	{
		name = n;
	}

	string getName() const	//dont need const ( I tried it too and it just gave me errors unless im wrong)
	{
		return name; 
	}
	virtual void setName() const = 0; //same here, dont need consts
	virtual void doAction() const = 0; 
	virtual void Speak() const = 0; 
};
#endif