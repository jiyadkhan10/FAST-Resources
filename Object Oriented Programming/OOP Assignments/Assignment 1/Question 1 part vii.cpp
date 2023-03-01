//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 1 part vii


#include <iostream>
#include <cstring>

using namespace std;

bool Compare_the_String(char *array, char compare)
{
	int s;
	
	int i = 0;
	while( *(array+i) != '0')
	{
		s++;
		i++;
	}
	
	int x = 0;
	while(x < s)
	{
		int y;
		y = *(array+x);
		
		if(y == compare)
		{
			return true;
		}
		else if (y == false)
		{
			return false;
		}
		x++;
	}
	return x;
}

int main()
{
	char array_of_string[50];
	char compare_the_string;
	bool comparing;
	
	cout << "Enter the string of the array: ";
	cin >> array_of_string;
	
	cout << "Enter the character from the string you want to compare: ";
	cin >> compare_the_string;
	
	comparing = Compare_the_String(array_of_string, compare_the_string);
	
	if (comparing == true)
	{
		cout << "Your character is already avaiable in the array." << endl;
    }
    
    else
	{
		cout << "Your character is not avaiable in the array." << endl;
    }

}
