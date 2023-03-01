//All rights reserved by Muhammad Jiyad Khan
//Name: Muhammad Jiyad Khan
//Roll no: 19I-1771
//Sectoion BS-(D)
//Assingment # 02
//Question 1 part iii

#include <iostream>
#include <cstring>

using namespace std;

bool Palindrome(string character)
{
	int length_of_string = character.length();
	
	int x = 0;
	int y = length_of_string-1;
	
	if (x < y)
	{
		if (character[x++] != character[y--])
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	string s;
	
	cout << "Enter the string: ";
	getline(cin,s);
	
	bool x = Palindrome(s);
	
	if(x == true)
	{
		cout << s << " is a palindrome. " << endl;
	}
	
	else if(x == false)
	{
		cout << s << " is not a palindrome. " << endl;
	}
	
	return 0;
}

