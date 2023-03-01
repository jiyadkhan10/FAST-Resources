//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q1

#include <iostream>

using namespace std;

class Point
{
	private:
		
    	double x, y;
    	
	public:
		
    	Point();
    	Point(double xy, double yx);
    	Point operator+(const Point& p2); // member overloading operator +
    	Point operator-(const Point& p2); // member overloading operator -
    	double distance(const Point& p);  //return distance of current point as p
    	double getX() const;
    	double getY() const;

};

