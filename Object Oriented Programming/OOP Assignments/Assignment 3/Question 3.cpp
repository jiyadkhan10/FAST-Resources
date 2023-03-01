//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 3
//Q3


#include <iostream>

using namespace std;

struct Circle
{
	private: //private data member
		
		float radius_of_circle;
		
	public:
		
		Circle() //default constructor
		{
			radius_of_circle = 1;
		}
		
		Circle(double radius) //parametized constructor
		{
			radius_of_circle = radius;
		}
		
		float getArea() //return the area
		{
			return (3.14 * (radius_of_circle) * (radius_of_circle));
		}
		
		float getCircumference() //retur the circumference
		{
			return (2 * 3.14 * (radius_of_circle));
		}
		
};

int main()
{
	double r;
	
	//Taking input by user
	cout << "Please specify the radius of your Circle: ";
	cin >> r;
	
	cout  << endl;
	
	cout << "Circle created. " << endl;
	
	cout << endl;
	
	Circle circle(r);
	
	//Output
	cout <<  "Area: " << circle.getArea() << endl;
	cout << "Circumference: " <<  circle.getCircumference() << endl;
	
	cout << endl;
	
	cout << "Goodbye!" << endl;
	
}
