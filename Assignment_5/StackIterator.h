#ifndef ITERATOR_H
#define ITERATOR_H
#include<iostream>
using namespace std;

template <class Type>
class StackIterator{

    private:
        Type info;
        Type current;
    public:

        
        StackIterator()
        {
            current = 0;
        }

        StackIterator(Type c)
        {
            current = c;
        }


        Type operator*()
        {
            return info;
        }

        StackIterator<Type> operator++()
        {
            current++;

            return current;
        }

};

    

#endif