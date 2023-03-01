//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q4

#include<iostream>
using namespace std;
class Fraction
{
	private:
		
    	long numerator;
    	long denominator;
    	
	public:
		
    	Fraction(long num = 0, long den = 1) //Function to find invalid input
    	{
    	    this->numerator = num;
    	    while (den == 0)
    	    {
    	        std::cout << "Error: The denominator is 0" << endl;
    	        std::cout << "New denominator != 0 : ";
    	        cin >> den;
    	    }
    	    
    	    this->denominator = den;
    	
		}
		
		//operation overloading
    	Fraction operator-();
    	Fraction operator++();
    	Fraction operator--();
    	Fraction operator+=(Fraction x);
    	Fraction operator-=(Fraction x);
    	Fraction operator*=(Fraction x);
    	Fraction operator/=(Fraction x);
    	
    	friend Fraction operator+(Fraction y, Fraction z);
    	friend Fraction operator-(Fraction y, Fraction z);
    	friend Fraction operator*(Fraction y, Fraction z);
    	friend Fraction operator/(Fraction y, Fraction z);
    	friend ostream& operator << (ostream& out, const Fraction& a);
    	friend istream& operator >> (istream& in, Fraction& b);
};
