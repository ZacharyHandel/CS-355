#ifndef INCREASING_H
#define INCREASING_H
#include "AbstractSort.h"
#endif

class Decreasing : public AbstractSort
{
    bool compare(int p, int q)  //compares if i < i+1
    {
        if(p < q)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};