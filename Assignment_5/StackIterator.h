#ifndef ITERATOR_H
#define ITERATOR_H
#include<iostream>
using namespace std;

template <class Type>
class StackIterator{

    private:
        int index;
        Type *current;

    public:
        StackIterator()
        {
            index = 0;
            current = nullptr;
        }

        StackIterator(Type *c, int i)
        {
            index = i;
            current = c;
        }

        Type operator++()
        {
            return index--;
        }

        Type operator*()
        {
            return current[index];
        }

        bool operator!=(int i)
        {
            return index != i;
        }

        bool operator==(int i)
        {
            return index == i;
        }

        void operator=(int i)
        {
            index = i;
        }



};

    

#endif