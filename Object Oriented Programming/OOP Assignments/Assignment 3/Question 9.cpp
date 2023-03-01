//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 3
//Q9

#include <iostream>

using namespace std;

struct Rectangle
{
	private: //Private Data Number
		
		float length;
		float width;
		
	public:
		
		Rectangle() //default constructor
		{
			length = 0;
			width = 0;
		}
		Rectangle(float l, float w)  //parametized constructor
		{
			length = l;
			width = w;
		}
		
		 //Function implementations
		 
		void setLength(float l)
		{
			length = l;
		}
		void setWidth(float w)
		{
			width = w;
		}
		float perimeter()
		{
			return (2*(length + width));
		}
		float area()
		{
			return(length + width);
		}
		void show()
		{
			cout << "Lenght: " << length << endl;
			cout << "Widht: " << width << endl;
		}
		int sameArea(Rectangle rectangle)
		{
			if (area() == rectangle.area())
			{
				return 1;
			}
			
			else
			{
				return 0;
			}		
		}
	
};

int main()
{
	float length_of_rectangle;
	float width_of_rectangle;
	
	Rectangle first_rectangle;  //Creating an obejct to first rectangle
	Rectangle second_rectangle(10,20);  //Creating an obejct to second rectangle 
	
	//Getting the values entered by the user
	cout << "Enter the length of the first rectangle: ";
	cin >> length_of_rectangle;
	
	cout << "Enter the width of the first rectangle: ";
	cin >> width_of_rectangle;
	
	//Setting the length and width of the first rectangle 
	first_rectangle.setLength(length_of_rectangle);
	first_rectangle.setWidth(width_of_rectangle);
	
	cout << endl;
	
	cout << "First Rectangle: " << endl;
	first_rectangle.show();
	
	cout << endl;
	
	cout << "Second Rectangle: " << endl;
	second_rectangle.show();
	
	cout << endl;
	
	//Area of both rectangle
	cout << "Area of first rectangle: " << first_rectangle.area() << endl;
	cout << "Area of second rectangle: " << second_rectangle.area() << endl;
	
	cout << endl;
    //Perimeter of both rectangle
	cout << "Perimeter of first rectangle: " << first_rectangle.perimeter() << endl;
	cout << "Perimeter of second rectangle: " << second_rectangle.perimeter() << endl;
	
	cout << endl;
	
	//Comparing both rectangle area
	if(second_rectangle.sameArea(first_rectangle))
	{
		cout << "Both rectangle have a same area. " << endl;
	}
	
	else
	{
		cout << "Both  rectangle doesn't have a same area. " << endl;
	}
		
	
	
}


