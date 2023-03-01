//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q5

#include <iostream>

using namespace std;

class Test
{
	private:
		
		long rupee;
		long paise;
		
	public:
		
		Test();
		Test(long rp, long pa);
		Test operator*(float rate);
		void operator=(Test a);
		void print();
};
