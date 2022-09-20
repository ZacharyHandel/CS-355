#ifndef CAT_H
#define CAT_H




#include "Mammal.h"
#include <iostream>

using namespace std;

class Cat : public Mammal
{
public: 
	Cat()
	{
		cout << "What is the name of your cat? " << endl;
	}
	void setName(string n)
	{
		name = n;
	}

	void doAction()
	{
		cout << "The cat named" << name << "goes preen" << endl;
	}

	void speak()
	{
		cout << "The cat named" << name << "says meow!" << endl;
	}
};
#endif
