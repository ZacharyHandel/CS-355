#include <iostream>
using namespace std;

class petType
{
    protected:
     string name;
    public:
      petType(string n="")    //default blank
      {
        name = n;
      }

      virtual void print() = 0; //whenever compiler, wait! Do not do static name binding but dynamic name binding. Wait because its not safe to assume that just because you are calling print from the base class there is not a derived class that has overriden the base class
      //now that it is 0, it is a pure virtual function. Now, we cannot declare only a petType 

};