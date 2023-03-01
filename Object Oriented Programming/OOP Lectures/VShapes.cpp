//vShapes.cpp
#include <iostream>
using namespace std;

/********************** Shape Class ***********************/
class Shape{
public:
    virtual void sayHi() { cout <<"Just hi! \n";}
};

/********************** Triangle Class ***********************/
class Triangle : public Shape{
public:
    virtual void sayHi() { cout <<"Hi from a triangle! \n";}
};


/********************** Rectangle Class ***********************/
class Rectangle : public Shape{
public:
    virtual void sayHi() { cout <<"Hi from a rectangle! \n"; }
};


/********************** main function ***********************/
int main( )
{
   Shape *p;
   int which;
   cout <<"1 -- shape, 2 -- triangle, 3 -- rectangle\n ";
   cin >> which;
   
   switch ( which ) 
   {
      case 1: p = new Shape; break;
      case 2: p = new Triangle; break;
      case 3: p = new Rectangle; break;
   }
   
    p -> sayHi(); // dynamic binding of sayHi()
    
    delete p; //deletes correspoding derived class object (Shape/Triangle/Rectangle)
}