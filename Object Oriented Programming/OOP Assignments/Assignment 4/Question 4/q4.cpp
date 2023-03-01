//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q4

#include"q4.h"
#include<iostream>
using namespace std;

//operator overloading
Fraction Fraction::operator-()
{
    Fraction f;
    f.numerator = -this->numerator;
    f.denominator = this->denominator;
    return f;
}

//operator overloading
Fraction Fraction::operator++()
{
    Fraction f;
    f.numerator = this->numerator + this->denominator;
    f.denominator = this->denominator;
    return f;
}

//operator overloading
Fraction Fraction::operator--()
{
    Fraction f;
    f.numerator = this->numerator - this->denominator;
    f.denominator = this->denominator;
    return f;
}

//operator overloading
Fraction Fraction::operator+=(Fraction x)
{
    Fraction f;
    f.numerator = (numerator * x.denominator + x.numerator * denominator);
    f.denominator = (denominator)*x.denominator;
    return f;
}

//operator overloading
Fraction Fraction::operator-=(Fraction x)
{
    Fraction f;
    f.numerator = (numerator * x.denominator - x.numerator * denominator);
    f.denominator = (denominator)*x.denominator;
    return f;
}

//operator overloading
Fraction Fraction::operator*=(Fraction x)
{
    Fraction f;
    f.numerator = (numerator * x.numerator);
    f.denominator = (denominator * x.denominator);
    return f;
}

//operator overloading
Fraction Fraction::operator/=(Fraction x)
{
    Fraction f;
    f.numerator = (numerator * x.denominator);
    f.denominator = (denominator * x.numerator);
    return f;
}

//operator overloading
Fraction operator+(Fraction y, Fraction z)
{
    Fraction f;
    f.numerator = (y.numerator * z.denominator + z.numerator * y.denominator);
    f.denominator = (y.denominator * z.denominator);
    return f;
}

//operator overloading
Fraction operator-(Fraction y, Fraction z)
{
    Fraction f;
    f.numerator = (y.numerator * z.denominator - z.numerator * y.denominator);
    f.denominator = (y.denominator * z.denominator);
    return f;
}

//operator overloading
Fraction operator*(Fraction y, Fraction z)
{
    Fraction f;
    f.numerator = y.numerator + z.numerator;
    f.denominator = (y.denominator * z.denominator);
    return f;
}

//operator overloading
Fraction operator/(Fraction y, Fraction z)
{
    Fraction f;
    f.numerator = y.numerator * z.denominator;
    f.denominator = y.denominator * z.denominator;
    return f;
}

//operator overloading
ostream& operator << (ostream& out, const Fraction& a)
{
    out << a.numerator << "/" << a.denominator << endl;
    return out;
}

//operator overloading
istream& operator >> (istream& in, Fraction& b)
{
    cout << "Enter numerator :";
    in >> b.numerator;
    cout << "Enter denominator";
    in >> b.denominator;
    return in;
}
