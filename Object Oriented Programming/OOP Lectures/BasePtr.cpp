#include<iostream> 
using namespace std; 

/**************************** Base Class **********************/
class Base 
{ 
public: 
	virtual void show() 
	{ 
		cout<<"\n Show In Base "; 
	} 
	
	void sayHello()
	{
	    cout<<"\n Hello (from Base)";
	}
}; 

/**************************** Derived Class **********************/
class Derived: public Base 
{ 
public: 
	int x; 
	
	Derived() 
	{ 
		x = 10; 
	} 
	
	virtual void show() 
	{ 
		cout<<"\n Show In Derived "; 
	} 
	
	void sayHello()
	{
	    cout<<"\n Hello (from Derived)";
	}
	
	void sayBye()
	{
	    cout<<"\n Bye (from Derived)";
	}
}; 

/******************************* main function ******************/
int main(void) 
{ 
	Base *bp, b; 
	Derived d; 
	bp = &d; 
	bp->show();      // Calling a virtual function
    bp->sayHello();  // Calling a function Base class's hello
    //bp->sayBye();  // ‘class Base’ has no member named ‘sayBye’
	//cout << bp->x; //‘class Base’ has no member named ‘x’	 
	return 0; 
} 