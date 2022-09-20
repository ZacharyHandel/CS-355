#ifndef HORSE_H
#define HORSE_H

#include "Mammal.h"
#include <iostream>

using namespace std;

class Horse : public Mammal
{
public: 
	Horse() 
	{
		cout << "What is the name of your horse? " << endl;
	}
	void setName(string n)
	{
		name = n;
	}

	void doAction()
	{
		cout << "The horse named" << name << "goes gallop" << endl;
	}

	void speak()
	{
		cout << "The horse named" << name << "says nay!" << endl;
	}

}; 
#endif
