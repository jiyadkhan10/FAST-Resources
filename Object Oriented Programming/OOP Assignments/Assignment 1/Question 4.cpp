//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 4

#include <iostream>

using namespace std;

int main()
{
	int size = 100;
	int *marks = new int[size];
	int x = 0;
	
	cout << "Enter -1 to exist." << endl;		
	cout << "Enter the marks of the student accordingly: " << endl;
	
	int i = 0;
	while(i < size)
	{
		cin >> marks[size];
		
		if(marks[size] == -1)
		{
			break;
		}
		
		x++;
	}
}
