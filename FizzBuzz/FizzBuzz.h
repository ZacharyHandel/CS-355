/*
Name- Zachary Handel
Assignment- Assignment 1 (header file)
Due Date- 8/24/22 at 11:59pm
Description- This is the header file of the project
*/
class FizzBuzz
{
public:
	FizzBuzz(int l)
	{
	limit = l;
	cout << "Setting Limit in Base Class Constructor" << endl;
	}

	void run()
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
	}

	void setLimit()
	{
	int value;
	cout << "Set a new limit value: " << endl;
	cin >> value;
	limit = value;
	}

	void printMenu()
{
	int choice;
	cout << endl << endl;
	cout << "********Menu********" << endl;
	cout << "1. Run Game" << endl;
	cout << "2. Set New Limit Value" << endl;
	cout << "3. Clear" << endl;
	cout << "4. Add a new parameter" << endl;
	cout << "5. Quit" << endl;
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
	}
}
protected:
	int limit;
};