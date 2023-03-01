//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 1 part iv

#include <iostream>
#include <cstring>

using namespace std;

int reverse_the_string(char *array)
{
	cout << "Print the character in the reverse order: ";
	
	char *x = array + (strlen(array) - 1);
	
	int i = 0;
	while(i < strlen(array))
	{
		cout << *x;
		x--;
		i++;
	}
	return 0;
}

int main()
{
	char *y = new char[100];
	
	cout << "Enter the string: ";
	cin >> y;
	
	reverse_the_string(y);
	
	return 0;
}
