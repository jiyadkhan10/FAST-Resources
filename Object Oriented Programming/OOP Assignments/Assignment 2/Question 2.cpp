//All rights reserved by Muhammad Jiyad Khan
//Name: Muhammad Jiyad Khan
//Roll no: 19I-1771
//Sectoion BS-(D)
//Assingment # 02
//Question 2

#include <iostream>

using namespace std;

struct phone_number {
	int area_code;
	int exchange_number;
	int number;
};

int main() {
	phone_number my_number;
	phone_number your_number;

	my_number.area_code = 212;
	my_number.exchange_number = 767;
	my_number.number = 8900;

	cout << "Enter your Area Code: ";
	cin >> your_number.area_code;
	
   	cout << "Enter your Exchange number: ";
	cin >> your_number.exchange_number;
	
	cout << "Enter your Number: ";
	cin >> your_number.number;
	
	cout << "My number is (" << my_number.area_code << ") " << my_number.exchange_number << "-" << my_number.number << endl; 
	cout << "Your number is (" << your_number.area_code << ") " << your_number.exchange_number << "-" << your_number.number << endl; 
}
