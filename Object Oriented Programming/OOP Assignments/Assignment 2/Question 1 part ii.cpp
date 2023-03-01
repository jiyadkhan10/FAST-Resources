//All rights reserved by Muhammad Jiyad Khan
//Name: Muhammad Jiyad Khan
//Roll no: 19I-1771
//Sectoion BS-(D)
//Assingment # 02
//Question 1 part ii


#include <iostream>
#include <cstring>

using namespace std;

bool isMember(char *array, char value)
{
	if(strlen(array) == 0)
	{
		return 0;
	}
	
	if(array[0] == value)
	{
		return true;
	}
	
	else
	{
		return isMember((array+1), value);
	}
}

int main()
{
	int size;
	char *element;
	char find_the_element;
	
	cout << "Enter the size of the array: " << endl;
	cin >> size;
	
	element = new char[size];
	
	cout << "Enter the character in the array: ";
	for(int i = 0; i < size; i++)
	{
		cin >> element[i];
	}
	
	cout << "Enter the character you want to find: ";
	cin >> find_the_element;
	
	bool x = isMember(element, find_the_element);
	
	cout << endl;
	
	if(x == true)
	{
		cout << find_the_element << " is a member of the array.";
	}
	
	else
	{
		cout << find_the_element << " is not a member of the array.";
	}
	
	return 0;
}

