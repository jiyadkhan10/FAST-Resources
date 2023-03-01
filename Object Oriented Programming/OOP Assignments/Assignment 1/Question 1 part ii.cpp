//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 1 part ii

#include <iostream>

using namespace std;

int swap_the_numbers(int *firstvalue, int *secondvalue)
{
	int x;
	
	x = *firstvalue;
	*firstvalue = *secondvalue;
	*secondvalue = x;
}

int main()
{
 	int first_number;
 	int second_number;
 	
 	cout << "Enter the first number: ";
 	cin >> first_number;
 	
 	cout << "Enter the second number: ";
 	cin >> second_number;
 	
 	cout << "First number: " << first_number << endl;
 	cout << "Second number: " << second_number << endl;
 	
 	swap_the_numbers(&first_number, &second_number);
 	
 	cout << "After Swapping: " << endl;
 	cout << "First number: " << first_number << endl;
 	cout << "Second number: " << second_number << endl;
 	
 	return 0 ;
}
