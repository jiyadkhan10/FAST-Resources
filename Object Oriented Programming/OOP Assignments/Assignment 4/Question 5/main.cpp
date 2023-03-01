//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q5

#include <iostream>
#include "q5.cpp"

using namespace std;

int main()
{
	//variable declaration
	long rupee;
	long paise;

	//get user input
	cout << "Enter your amount in Rupees: ";
	cin >> rupee;
	cout << "Enter paise: ";
	cin >> paise;

	//create objects
	Test obj1(rupee, paise);
	Test obj2(0, 0);
	
	cout << "The amount in Rupees ";
	obj1.print();
	
	obj2 = (obj1 * 0.12);

	//display the result
	cout << endl << "After multiplying by rate 0.12" << endl;
	cout << "The amount of interest in rupees is: ";
	obj2.print();

	return 0;
}
