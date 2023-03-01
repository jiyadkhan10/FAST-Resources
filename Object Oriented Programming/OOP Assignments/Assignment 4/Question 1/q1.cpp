//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q1

#include "q1.h"
#include<cmath>

//default constructor
Point::Point() 
{
	x = 0;
	y = 0;
}

//parameterized constructor
Point::Point(double xy, double yx) 
{
	x = xy;
	y = yx;
}

// member overloading operator +
Point Point::operator+(const Point& p2)
{
    return Point(x + p2.x, y + p2.y);
}

// member overloading operator -
Point Point::operator-(const Point& p2) 
{
    return Point(x - p2.x, y - p2.y);
}

//return distance of current point as p
double Point::distance(const Point& p) 
{
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

// return the x
double Point::getX() const 
{ 
	return x; 
}

//return the y
double Point::getY() const 
{ 
	return y; 
}
