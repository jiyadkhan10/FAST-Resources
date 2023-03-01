//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q4

#include<iostream>
#include"q4.cpp"
using namespace std;


using namespace std;
int main()
{
    Fraction a(5, 3), b(2);   //variable declaration
    cout << a << b << endl;   // output of the variable declaration
      
	//display the result   
    cout << (a + b) << endl;
    cout << (a - b) << endl;
    cout << (a * b) << endl;
    cout << (a / b) << endl;
    cout << (--a) << endl;
    cout << (++a) << endl;
    cout << (-b) << endl;
    
    Fraction c(1, 2); //create objects
    
    a += c;
    cout << a << endl;
    a -= c;
    cout << a << endl;
}
