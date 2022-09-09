#include<iostream>
using namespace std;

class Item
{
    private:
        string itemName;
        string itemDescription;
        int srItems;
    public:
        void setName(string name)
        {
            itemName = name;
        }

        void setDesc(string desc)
        {
            itemDescription = desc;
        }

        void setSR(int sr)
        {
            srItems = sr;
        }

        string getName()
        {
            return itemName;
        }

        string getDesc()
        {
            return itemDescription;
        }

        int getSR()
        {  
            return srItems;
        }

        void displayName()
        {
            cout << itemName << endl;
        }

        void displayDesc()
        {
            cout << itemDescription << endl;
        }

        friend ostream& operator << (ostream& output, Item& item)
        {
            output << item.itemName << endl;
            output << item.itemDescription << endl;
            output << item.srItems << endl;
        }

};