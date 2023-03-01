//============================================================================
// Name        : Test.cpp
// Author      : Hassan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
template<class T>
class Arr{
	T *ptr;
	int size;
public:
	Arr(){
		ptr=NULL;
		size=0;
	}
	Arr(int s, T iv){
		size=s;
		ptr=new T[size];
		for(int i=0; i<size;i++){
			ptr[i]=iv;
		}
	}
	void display(){
		for(int i=0; i<size;i++){
					cout<<ptr[i]<<"  ";
				}
		cout<<endl;
	}
	T& operator[](int i){
		if(i>=0 && i<size)
			return ptr[i];
	}

};

int main () {
	Arr<int> a1(5, 0);
	a1[3]=12;
	a1.display();

	Arr<char> carr(6,'H');
	carr[2]='B';
	carr.display();



  return 0;
}

