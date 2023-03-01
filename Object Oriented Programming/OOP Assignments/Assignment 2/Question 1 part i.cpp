//All rights reserved by Muhammad Jiyad Khan
//Name: Muhammad Jiyad Khan
//Roll no: 19I-1771
//Sectoion BS-(D)
//Assingment # 02
//Question 1 part i


#include <iostream>

using namespace std;

int raised_the_power_number(float number_raised_to_power, unsigned int power)
{
	if(power != 0)
	{
		return number_raised_to_power * raised_the_power_number(number_raised_to_power, power - 1);
	}
	
	else if (power == 0)
	{
		return 1;
	}
}

int main()
{
	unsigned int exponent;
	float base;
	
	cout << "Enter the base number: " << endl;
	cin >> base;
	
	cout << "Enter the exponent number: " << endl;
	cin >> exponent;
	
	int x = raised_the_power_number(base, exponent);
	
	cout << "Result: " << x << endl;
	
	return 0;
}
