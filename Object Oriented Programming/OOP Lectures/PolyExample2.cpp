// PolyExample2.cpp
#include <iostream>
using namespace std;

/************************** Shape Class *************************/
class Shape {
    public:
        virtual void sayHi() { 
            cout <<"Just hi! \n";
        }
};

/************************** Triangle Class *************************/
class Triangle : public Shape {
    public:
    
    // overrides Shape::sayHi(), automatically virtual (optional to specify overide keyword)
    // Try signature --> virtual void sayHi() override {
    void sayHi()  {
        cout <<"Hi from a triangle! \n";
    }
};

/************************** print function *************************/
void print(Shape obj, Shape *ptr, Shape &ref) {
    ptr -> sayHi(); // bound at run-time
    ref.sayHi(); // bound at run-time
    obj.sayHi(); // bound at compile-time
}

/************************** main function *************************/
int main()
{
    Triangle mytri;
    print( mytri, &mytri, mytri );
}