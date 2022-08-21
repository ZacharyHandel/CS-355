#include <iostream>
using namespace std;

int main()
{
    string name;
    int favNum;
    cout << "Hello! What is your name?" << endl;
    cin >> name;
    cout << "Hello, " << name << endl;
    
    cout << "What is your favorite number? I will add 3 to it!" << endl;
    cin >> favNum;
    favNum += 3;
    cout << "the new number is now " << favNum << endl;

    cout << "Input either 1 or 2. If you say 1, I will say yay! if you say 2, I will say boo!" << endl;
    int choice;

    if(choice == 1)
    {
        cout << "YAY!" << endl;
    }
    else if(choice == 2)
    {
        cout << "BOO!" << endl;
    }
    else
    {
        cout << "You did not even input one of the choices I suggested... Goodbye!" << endl;
    }

    return 0;
}