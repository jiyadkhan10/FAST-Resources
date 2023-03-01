//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 1 part i

#include <iostream>

using namespace std;

int maximun_number(int *array, int number)
{
	int maximun = 0;
	int i = 0;
	while(i < number)
	{
		if (*array > maximun)
		{
			maximun = *array;
			array++;
		}
		else
		{
			array++;
		}
		i++;
	}
	return maximun;
}

int main()
{
	int number;
	
	cout << "Enter the size of the array: ";
	cin >> number;
	
	int *x = new int(number);
	int *y = x;
	
	cout << "Enter the element in the array: " << endl;
	
	int i = 0;
	while(i < number)
	{
		cin >> *y;
		y++;
		i++;
	}
	
	int max = maximun_number(x, number);
	cout << "The maximun number of the array is: " << max;
	
	return 0;	
}
