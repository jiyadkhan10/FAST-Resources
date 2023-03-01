//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 3
//Q7

#include <iostream>

using namespace std;

class Account
{
	public:
		
		float balance;
		
		Account()
		{
			balance = 0;
		}
		
		Account(float b)
		{
			balance = b;
		}
		
		void deposit(float amount)
		{
			balance += amount;
		}
		
		float inquire()
		{
			return balance;
		}
		
		bool withdraw(float amount)
		{
			if(balance >= amount)
			{
				balance -= amount;
				return true;
			}
			else
			{ 
			    //deduct the $5 for attempting the withdraw more than balance
				balance -= 5;
				return false;
			}
		}
};

int main()
{
	// Account Class with default constructor
	cout << "Creating a first Account without initial balance. " << endl;
	Account first_account;
	
	cout << "Balance in first account: " << first_account.inquire() << endl;
	
	cout << endl;
	
	// Account Class with parameterized constructor
	cout << "Creating a second Account with initial balance of 100. " << endl;
	Account second_account(100);
	
	cout << "Balance in second account: " << second_account.inquire() << endl;
	
	cout << endl;
	
	cout << "Withdraw a $10 from the first account: " << first_account.withdraw(10) << endl; // Withdraw a $10
	cout << "Balance after withdrawal in the first account: $" << first_account.inquire() << endl;
	
	cout << endl;
	
	cout << "Withdraw a $10 from the second account: " << second_account.withdraw(10) << endl;
	cout << "Balance after withdrawal in the second account: $" << second_account.inquire() << endl;
	
	cout << endl;
}
