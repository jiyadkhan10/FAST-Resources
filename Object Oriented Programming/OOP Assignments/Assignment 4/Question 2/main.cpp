//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q2

#include<iostream>
#include<iomanip>
#include "q2.cpp"

using namespace std;

int main()
{
    Point p1(2.0, 1.0), p2(5.0, 4.0);
    
    std::cout << "Point p1 is : ";
    p1.print();
    
    cout << endl;
    
    std::cout << "Point p1 is : ";
    p2.print();
    
    cout << endl;
    
    Point p3 = p1 + p2;
    std::cout << "p1+p2 is : ";
    p3.print();
    
    cout << endl;
    
    Point p4 = p1 - p2;
    std::cout << "p1-p2 is : ";
    p4.print();
    
    cout << endl;
    
    std::cout << "The distance fom p1 to p2 is : " << distance(p1, p2);
}
