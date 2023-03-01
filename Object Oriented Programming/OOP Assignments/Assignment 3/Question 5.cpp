//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 3
//Q5

#include <iostream>

using namespace std;

struct Employee2
{
	private: //private data member
		
		char *name;
		float HourlyWage;
		float WorkedHours;
		float ExtraHours;
		
	public:
		
		float wageCalculator() //reads the name and hourly wage of an employee
		{
			float total_payment;
			float extra_wage;
			name = new char[100];
			
			cout << "Please Enter the name of the employee: ";
			cin.getline(name, 100);
			
			cout << "Please Enter Hourly Wage of employee: ";
			cin >>  HourlyWage;
			
			cout << "Please Enter Hours worked by employee: ";
			cin >>  WorkedHours;
			
			cout << endl;
			
			cout << "Pay Check for employee: " << name << endl;
			
			cout << endl;
			
			if(WorkedHours > 40) //Over time worked if the employee work more than 40 hours
			{
				ExtraHours = WorkedHours - 40;
				
				cout << "Hours Worked: " << WorkedHours << endl;
				cout << "Hourly Wage: " << HourlyWage << endl;
				cout << "Extra Hours: " << ExtraHours << endl; //Extra Hours
				
				extra_wage = (150.0/100) * HourlyWage; //Extra Wage
				
				cout << "Over time Hourly Wage: " << extra_wage << endl;
				
				total_payment = (HourlyWage * 40) + (extra_wage * ExtraHours);
				
				cout << "Total Payment: " << total_payment; //Total Wage with Extra Wage
			}
			
			else
			{
				cout << "Hour Worked: " << WorkedHours << endl;
				cout << "Hourly Wage: " << HourlyWage << endl;
				
				total_payment = HourlyWage * WorkedHours; //Total Hours
				
				cout << "Total Payment: " << total_payment;
			}
			
		}
		
};

int main()
{
	Employee2 x;
	x.wageCalculator();
}
