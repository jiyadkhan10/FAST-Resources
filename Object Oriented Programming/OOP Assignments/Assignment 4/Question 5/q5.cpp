//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q5

#include <iostream>
#include "q5.h"

using namespace std;

//default constructor
Test::Test()
{
	rupee = 0;
	paise = 0;
}

//parameterize constructor
Test::Test(long rp, long pa)
{
	rupee = rp;
	paise = pa;
}

//operator overloading
Test Test::operator*(float rate)
{
	long total = rupee + paise / 100;
	total = total * rate;
	rupee = (int)(total * 100) / 100;
	paise = (int)(total * 100) % 100;

	return *this;
}

//operator overloading
void Test::operator=(Test a)
{
	rupee = a.rupee;
	paise = a.paise;
}

//print the amount
void Test::print()
{
	long total = rupee + paise / 100;
	cout << total;
}
