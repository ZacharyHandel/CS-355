#include <iostream>
using namespace std;

#include "HashChainType.h"

int main(){
	hashChainType<int> myHT(10);

	for(int i=0; i<100; i++){
		myHT.insert(i);
	}

	myHT.print();

	bool test = false;

	myHT.search(50, test);

	if(test){
		cout<<"found 50"<<endl;
	}
	else{
		cout<<"50 not found"<<endl;
	}

	myHT.search(105, test);
	if(test){
		cout<<"found 105"<<endl;
	}
	else{
		cout<<"105 not found"<<endl;
	}

	myHT.insert(105);

	myHT.print();

	myHT.search(105, test);
	if(test){
		cout<<"found 105"<<endl;
	}
	else{
		cout<<"105 not found"<<endl;
	}

	myHT.remove(15);

	myHT.print();

	myHT.search(15, test);
	if(test){
		cout<<"found 15"<<endl;
	}
	else{
		cout<<"15 not found"<<endl;
	}

}
