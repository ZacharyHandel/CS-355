#ifndef GUINEAPIG_H
#define GUINEAPIG_H

#include "Mammal.h"
#include <iostream>

using namespace std; 

class GuineaPig : public Mammal
{
public: 
	GuineaPig() 
	{ 
		cout << "What is the name of your GuineaPig? " << endl;
	}
	void setName(string n)
	{
		name = n; 
	}

	void doAction()
	{
		cout << "The guniea pig named" << name << "goes skitter" << endl; 
	}

	void speak()
	{
		cout << "The guniea pig named" << name << "says weep wweep!" << endl;
	}
};
#endif // !GUINEAPIG_H

