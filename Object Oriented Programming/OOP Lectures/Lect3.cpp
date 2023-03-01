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
class Student{
	string name;
	double cgpa;
public:
	Student(){
		name="";
		cgpa=0;
	}
	Student(string s, double c){
		name=s;
		cgpa=c;
	}
	void display(){
		cout<<name<<endl;
		cout<<cgpa<<endl;
	}

	double getCgpa() const {
		return cgpa;
	}

	void setCgpa(double cgpa) {
		this->cgpa = cgpa;
	}

	const string& getName() const {
		return name;
	}

	void setName(const string &name) {
		this->name = name;
	}
};
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
	Arr(Arr<T> &cp){
		size=cp.size;
		ptr=new T[size];
		for(int i=0; i<size;i++){
					ptr[i]=cp.ptr[i];
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
	for(int i=0; i<5;i++)
		a1[i]=i+1;

	//Arr<Student> sarr(4,Student("Hassan",3.6));
	Arr<Arr<int>> a2(12,a1);

	Arr<Arr<Arr<int>>> a3(6,a2);
	cout<<a3[0][0][4];


  return 0;
}

