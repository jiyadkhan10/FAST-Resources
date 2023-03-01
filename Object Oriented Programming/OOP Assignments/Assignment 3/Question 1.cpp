//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 3
//Q1

#include <iostream>
#include <iomanip>

using namespace std;

struct Employee
{
	private:     //private data member
		char *name;
		double salary;
	
	public:
		
		Employee() //default constructor
		{
			name = new char[100];
			salary = 0;
		}
		
		Employee(char *n, double s) //parametized constructor
		{
			if(s > 0)
			{
				salary = s;
				name = n;
			}
		}
		
		char* getName() //return the area
		{
			return name;
		}
		
		double getSalary() //return the salary
		{
			return salary;
		}
		
};

void TestEmployee() // Function to take input and give output
{
	char *n = new char[100];
	double s;
	
	cout << "Creating a new employee. " << endl;
	
	cout << endl;
	
	//Taking input by user
	cout << "Please type the name: ";
    cin.getline(n, 100);
    
	cout << endl;
	
	cout << "Please specify the salary: ";
	cin >> s;
	
	cout << endl;
	
	cout << "New Employee has been created. " << endl;
	
	cout << endl;
	
	Employee test(n,s); //Recalling the function
	
	//Output
	cout << "Name of Employee: " << test.getName() << endl;
	cout << "Salary: " << fixed << setprecision(1) << test.getSalary() << endl;
	
	cout << endl;
	
	cout << "Thankyou for testing structure employee. " << endl;
	
}

int main()
{
	TestEmployee();
}
