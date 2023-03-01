//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 1 part vi

#include <iostream>

using namespace std;

int Count_Even_Numbers(int *array, int lenght)
{
	int sum_the_even_numbers = 0;
	
	int i = 0;
	while(i < lenght)
	{
		int x;
		x = *(array+i);
		if (x % 2 == 0)
		{
			sum_the_even_numbers++;
		}
		i++;
	}
	
	return sum_the_even_numbers;
}

int main()
{
	int *Even_Numbers;
	int size;
	int x = 0;
	
	cout << "Enter the size of the array: ";
	cin >> size;
	
	Even_Numbers = new int[size];
	
	cout << "Enter the values of the Array: " << endl;
	
	int i = 0;
	while(i < size)
	{
		cin >> *(Even_Numbers+i);
		i++;
	}
	
	x = Count_Even_Numbers( Even_Numbers, size);
	
	cout << "There are " << x << " even numbers from the values of the array that you are given."; 
}
