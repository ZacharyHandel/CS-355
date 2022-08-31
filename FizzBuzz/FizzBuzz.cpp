/*
Name- Zachary Handel
Assignment- Assignment 1
Due Date- 8/24/22 at 11:59pm
Description- This is the implimentation file for FizzBuzz.h
*/
#include <iostream>
#include "FizzBuzz.h"

using namespace std;

/*
Function Name: fizzBuzz (constructor)
Input: None
Output:Default limit of 100
Return: None
*/
fizzBuzz::fizzBuzz()
{
	limit = 100;
}

/*
Function Name: run
Input: None
Output: The actual game function. Runs the logic of the game FizzBuzz
Return: None
*/
void fizzBuzz::run()
{
	for (int i = 1; i <= limit; i++)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
		{
			cout << "FizzBuzz" << endl;
		}
		else if (i % 3 == 0)
		{
			cout << "Fizz" << endl;
		}
		else if (i % 5 == 0)
		{
			cout << "Buzz" << endl;
		}
		else
		{
			cout << i << endl;
		}

	}
	printMenu();
}

/*
Function Name: setLimit
Input: None
Output: New limit value
Return: None
*/
void fizzBuzz::setLimit()
{
	int value;
	cout << "Set a new limit value: " << endl;
	cin >> value;
	limit = value;
	printMenu();
}

/*
Function Name: printMenu
Input: None
Output: Menu Screen 
Return: None
*/
void fizzBuzz::printMenu()
{
	int choice;
	cout << " ______ _         ____  _    _        " << endl;
	cout << "|  ____(_)       |  _ \ | |  | |        " << endl;
	cout << "| |__   _ _______| |_) | |  | |________" << endl;
	cout << "|  __| | |_  /_  /  _ <| |  | |_  /_  /" << endl;
	cout << "| |    | |/ / / /| |_) | |__| |/ / / / " << endl;
	cout << "|_|    |_/___/___|____/  \____//___/___|" << endl;
	cout << endl << endl;
	cout << "********Menu********" << endl;
	cout << "1. Run Game" << endl;
	cout << "2. Set New Limit Value" << endl;
	cout << "3. Quit" << endl;
	cin >> choice;
	if (choice == 1)
	{
		run();
	}
	else if (choice == 2)
	{
		setLimit();
	}
	else if (choice == 3)
	{
		cout << "Goodbye!" << endl;
		exit(0);
	}
	else
	{
		cout << "Error: Invalid Value Inputted. Retry" << endl;
		printMenu();
	}
}
