//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 1 part iii

#include <iostream>

using namespace std;

int *CopytheArray(int *array1, int *array2, int firstnumber, int secondnumber)
{
	int *new_Array = new int(firstnumber + secondnumber);
	int *x = new_Array;
	
	int i = 0;
	while( i < firstnumber)
	{
		*x = *array1;
		x++;
		array1++;
		i++;
	}
	
	int j = 0;
	while(j < secondnumber)
	{
		*x = *array2;
		x++;
		array2++;
		j++;
	}
	
	return new_Array;
}

int main()
{
 	int first_number_of_size;
 	int second_number_of_size;
 	
 	cout << "Enter the size of the first array: ";
 	cin >> first_number_of_size;
 	
 	cout << "Enter the size of the second array: ";
 	cin >> second_number_of_size;
 	
 	int *y = new int(first_number_of_size);
 	int *z = new int(second_number_of_size);
 	
 	cout << "Enter the element of the first array: " << endl;
 	int *a = y;
 	int i = 0;
 	while(i < first_number_of_size)
 	{
 	     cin >> *a;
		 a++;
		 i++;	
	}
	
	cout << "Enter the element of the second array: " << endl;
 	a = z;
 	int j = 0;
 	while(j < second_number_of_size)
 	{
 	     cin >> *a;
		 a++;
		 j++;	
	}
	
	int *b = CopytheArray(y, z, first_number_of_size, second_number_of_size);
	cout << "Combining the two array: ";
	
	int k = 0;
	while(k < (first_number_of_size+second_number_of_size))
	{
		cout << *b << " ";
		b++;
		k++;
	}
	
	return 0;
}
