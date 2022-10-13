#ifndef H_HashChainType
#define H_HashChainType

#include "HashADT.h"

using namespace std;

template <class elemType>
class hashChainType: public hashADT<elemType>
{
public:
	hashChainType(int size = 101): hashADT<elemType>(size)
	{
		//no additional action required
	}
	void insert(const elemType& rec);
		//Function to insert an item in the hash table.
		//The item to be inserted is specified by the parameter rec.
		//	Postcondition: rec is inserted in the proper list (create
		//   the list if not already created).

	void search(const elemType& rec, bool& found);
		//Function to determine whether the item specified by the
		//parameter rec is in the hash table.
		//Postcondition: If rec is found, found is set to true,
		//found is set to false.


	void remove(const elemType& rec);
		//Function to remove an item from the hash table.
		//Postcondition: If rec is found in the table it is removed;
		//otherwise, an appropriate error message is displayed.

	void print() const;
		//Function to output the values in the hash table.
};

template <class elemType>
void hashChainType<elemType>::insert(const elemType& rec){
	elemType n = this->getHash(rec);

	unorderedLinkedList<elemType> *index = this->HTable[this->getHash(rec)];

	if(index == nullptr)
	{
		index = new unorderedLinkedList<elemType>();
	}
	this->HTable[this->getHash(rec)] = index;

	index->insertLast(rec);
}

template <class elemType>
void hashChainType<elemType>::search(const elemType& rec, bool& found){
	elemType n = this->getHash(rec);
	found = this->HTable[n]->search(rec);
}
template <class elemType>
void hashChainType<elemType>::remove(const elemType& rec){
	elemType n = this->getHash(rec);
	this->HTable[n]->deleteNode(rec);
}

template <class elemType>
void hashChainType<elemType>::print() const{
	for(int i =0; i < this->HTSize; i++)
	{
		if(this->HTable[i] != nullptr)
		{
			this->HTable[i]->print();
		}
		cout << endl;
	}
	cout << endl;
}

#endif
