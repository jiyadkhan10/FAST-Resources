//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q2

#include "q2.h"
#include<iostream>
#include<iomanip>
#include<cmath>

//parameterized constructor
Point::Point(double xy, double yx) 
{
    x = xy;
    y = yx;
}

//to return the x 
double Point::getX() 
{ 
	return x; 
}

//to return the y
double Point::getY()
{
	return y; 
}

//to print the points 
void Point::print() 
{
    std::cout << std::fixed << std::setprecision(1) << " ( " << x << " , " << y << " ) ";
}

//to add two point
Point operator+(Point& p1, Point& p2) 
{
    Point p(p1.getX() + p2.getX(), p1.getY() + p2.getY());
    return p;
}

//to subtract two points 
Point operator-(Point& p1, Point& p2)
{
    Point p(p1.getX() - p2.getX(), p1.getY() - p2.getY());
    return p;
}

//to calculate the distance 
double distance(Point& p1, Point& p2)
{
    double x = p1.getX() - p2.getX();
    double y = p1.getY() - p2.getY();
    double dis = sqrt(x * x + y * y);
    return dis;
}
