#include <iostream>
#include <time.h>
using namespace std;

class QuickSort
{
    private:
        int size;
        int *list;
    public:
        QuickSort(int size = 10)
        {
            this->size = size;
            list = new int[size];
            fill(list);
        }

        int partition(int list[], int first, int last)
        {
            int pivot;

            int smallIndex;

            swap(list, first, (first + last) / 2);

            pivot = list[first];
            smallIndex = first;

            for(int i = first + 1; i <= last; i++)
            {
                if(list[i] < pivot)
                {
                    smallIndex++;
                    swap(list, smallIndex, i);
                }
            }

            swap(list, first, smallIndex);
            return smallIndex;
        }

        void swap(int list[], int first, int second)
        {
            int temp;

            temp = list[first];
            list[first] = list[second];
            list[second] = temp;
        }

        void recQuickSort(int list[], int first, int last)
        {
            int pivotLocation;

            if(first < last)
            {
                pivotLocation = partition(list, first, last);
                recQuickSort(list, first, pivotLocation - 1);
                recQuickSort(list, pivotLocation + 1, last);
            }
        }

        void quickSort()
        {
            recQuickSort(this->list, 0, size - 1);
        }

        void display()
        {
            for(int i = 0; i < this->size; i++)
            {
                cout << list[i] << endl;
            }
        }

        void fill(int list[])
        {
            srand(time(NULL));

            for(int i = 0; i < this->size; i++)
            {
                list[i] = rand() %100 + 1;
            }
        }

        void print()
        {
            for(int i = 0; i < this->size; i++)
            {
                cout << list[i] << endl;
            }
        }
};