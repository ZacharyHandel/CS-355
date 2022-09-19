#include<iostream>
#include<time.h>

using namespace std;

const int MAX_ARRAY_SIZE = 10;

class AbstractSort
{
    protected:
        int* ptr;
    public:

    
        AbstractSort()  //constructor
        {
            ptr = new int[MAX_ARRAY_SIZE];  //dynamically allocation a new int array
            srand(time(0)); //random number seed
        }

        void randomFill()   //fills array with random numbers between 1 and 100
        {
            for(int i = 0; i < MAX_ARRAY_SIZE; i++)
            {
                ptr[i] = 1 + (rand() % 100);
            }
        }

        void print()    //prints out the list of numbers in the array
        {
            for(int i = 0; i < MAX_ARRAY_SIZE; i++)
            {
                cout << ptr[i] << endl;
            }
        }

        virtual bool compare(int p, int q) = 0; //pure virtual method for compare

        void sort() //sorts the list based on what comarison we are using
        {
            /*
            int count;
           // bool flag;
            while(true)     ATTEMPT 2!!!! Works, but I didn't like the logic
            {
                //flag = false;
                count = 0;  //resets when sorting loop is done
                for(int i = 0; i < 9; i++)
                {
                    if(compare(ptr[i],ptr[i+1]))
                    {
                        int temp = ptr[i];  //swap
                        ptr[i] = ptr[i+1];
                        ptr[i+1] = temp;
                        //flag = true;
                        count++;    //will not count if list is sorted
                    }  

                }
                if(count == 0)     //if "list is sorted"
                {
                    break;
                }
            }*/

            /*int temp;                                     ATTEMPT 1!!!!
            for(int i = 0; i < MAX_ARRAY_SIZE-1; i++)
            {
                for(int j = 0; j < MAX_ARRAY_SIZE-1; j++)
                {
                    if(compare(ptr[i],ptr[j]))
                    {
                        temp = ptr[i];
                        ptr[i] = ptr[j];
                        ptr[j] = temp;
                    }
                }
            }*/

            int minIndex;               //ATTEMPT 3!!!! Makes most sense to me
            int temp;

            for(int i = 0; i < MAX_ARRAY_SIZE - 1; i++)
            {
                minIndex = i;
                for(int j = i+1; j < MAX_ARRAY_SIZE; j++)
                {
                    if(compare(ptr[minIndex],ptr[j]))
                    {
                        minIndex = j;
                    }
                }
                temp = ptr[minIndex];
                ptr[minIndex] = ptr[i];
                ptr[i] = temp;
            }
        }
};