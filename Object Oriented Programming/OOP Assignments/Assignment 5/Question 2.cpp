//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 5
//Q2


#include <iostream>

using namespace std;

class Employee 
{
	private:
		
		//Declaring variables
		string employee_name;
		string hire_date;
		int employee_number;
		
	public:
		
		//Default Constructor
		Employee() 
		{
			employee_name = ' ';
			employee_number = 0;
			hire_date = ' ';
		}
		
		 //Parameterized constructor
		Employee(string e_name, int e_number, string h_date) 
		{
			this->employee_name = e_name;
			this->employee_number = e_number;
			this->hire_date = h_date;
		}
		
		//Setters and Getters
		string get_Employee_name() 
		{
			return employee_name;
		}
		
		void set_Employee_name(string e_name) 
		{
			this->employee_name = e_name;
		}
		
		int get_Employee_number() 
		{
			return employee_number;
		}
		
		void set_Employee_number(int e_number) 
		{
			this->employee_number = e_number;
		}
		
		string get_hire_date() 
		{
			return hire_date;
		}
		
		void set_hire_date(string h_date) 
		{
			this->hire_date = h_date;
		}
		
		void Employee_Output() 
		{
			cout << endl;
			
			cout << "Employee Name: " << employee_name << endl;
			cout << "Employee Number: " << employee_number << endl;
			cout << "Hire Date: " << hire_date << endl;
		}
};

class ShiftSupervisor: public Employee
{
	private :
		
		//Declaring instance variables
		double annual_salary;
		double annual_bonus;
		
	public :

		 //Parameterized constructor
		ShiftSupervisor(string e_name, int e_number, string h_date, double a_salary, double a_bonus):Employee(e_name, e_number, h_date) 
		{		
			this->annual_salary = a_salary;
			this->annual_bonus = a_bonus;
		}
		
		//Setters and Getters
		double get_Annual_salary() 
		{
			return annual_salary;
		}
		
		void set_Annual_salary(double a_salary)
		{
			this->annual_salary = a_salary;
		}
		
		double get_Annual_bonus() 
		{
			return annual_bonus;
		}
		
		void set_Annual_bonus(double a_bonus) 
		{
			this->annual_bonus = a_bonus;
		}
		
		//toString() method which displays the contents of an Object inside it.
		void Output() 
		{
			Employee::Employee_Output();
			cout << "Annual Salary: $" << annual_salary << endl;
			cout << "Annual Bonus: $" << annual_bonus << endl;
			cout << "Total Salary: $" << (get_Annual_salary() + get_Annual_bonus()) << endl;
		}
};


int main ()
{
	string employee_name;
	string hire_date;
	int employee_number;
	double annual_salary;
	double annual_bonus;
        
    //Taking the Worker Details
    cout << "Enter Employee Name: ";
    getline(cin, employee_name);
    
    cout << "Enter Employee Number: ";
    cin >> employee_number;
    
    cout << "Enter Hire Date: ";
	cin >> hire_date;
    
    cout << "Enter Annual Salary: ";
    cin >> annual_salary;
    
    cout << "Enter Annual Bonus: ";
    cin >> annual_bonus;
        
    cout << endl;
	
	//Creating the Shift Supervisor Object by passing the parameters
	ShiftSupervisor x(employee_name, employee_number, hire_date, annual_salary, annual_bonus);
  
	//Displaying the Shift Supervisor details.
	cout << "-------- Shift Supervisor Details --------" << endl;
	x.Output();

	return 0;
}
