//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q1

#include <iostream>
#include<iomanip>
#include "q1.cpp"

using namespace std;


int main()
{
    //create objects
    Point p1(2.0, 1.0);
	Point p2(5.0, 4.0); 
    Point add = p1 + p2;
    Point sum = p2 - p1;

    cout << setprecision(1) << fixed << showpoint; //setprecision
    
    //display the result
    cout << "Point p1 is: (" << p1.getX() << "," << p1.getY() << ")" << endl;
    cout << "Point p1 is: (" << p2.getX() << "," << p2.getY() << ")" << endl;

    cout << "p1 + p2 : (" << add.getX() << "," << add.getY() << ")" << endl;
    cout << "p2 - p1 : (" << sum.getX() << "," << sum.getY() << ")" << endl;

    cout << "The distance from p1 to p2: " << p1.distance(p2) << endl;
}
