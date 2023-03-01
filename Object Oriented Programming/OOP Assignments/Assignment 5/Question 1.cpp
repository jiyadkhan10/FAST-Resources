//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 5
//Q1

#include <iostream>  

using namespace std;
  
class Employee 
{
        public:
        	
            //Employee variables
            string employee_name;
            int employee_number;
            string hire_date;
			
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
                
};  

//Inheriting Employee 
class ProductionWorker: public Employee 
{  
    public:
    	
        //ProductionWorker variables   
        int shift;
        double hourly_pay;
                
        //Parameterized Constructor
        ProductionWorker(string e_name, int e_number, string h_date, int s, double h_pay):Employee(e_name, e_number, h_date) 
		{
            this->hourly_pay = h_pay;
            this->shift = s;
        }
        
        double get_Hourly_pay() const
		{
			 return hourly_pay; 
		}
		
		void set_Hourly_pay(double h_pay)
		{ 
			hourly_pay = h_pay; 
		}
        
        int get_Shift()
		{	
			return shift; 
		}
        
        void set_Shift(int s)
		{ 
			shift = s; 
		}
		
		string get_Shift_Time() const
		{ 
			if (shift == 1)
			{
				return "Day";
			}
			
			else if (shift == 2)
			{
				return "Night";
			}
			
			else
			{
				return "Invalid";
			}
}

};
       
int main() 
{
    string employee_name;
	string hire_date;
    int employee_number;
	int shift;
    double hourly_pay;
        
    //Taking the Worker Details
    cout << "Enter Employee Name: ";
    getline(cin, employee_name);
    
    cout << "Enter Employee Number: ";
    cin >> employee_number;
    
    cout << "Enter Hire Date: ";
    cin >> hire_date;
    
    cout << "Enter Shift 1-Day / 2-Night: ";
    cin >> shift;
    
    cout << "Enter Hourly Pay: ";
    cin >> hourly_pay;
        
    cout << endl;
        
    //Initializing Production Worker Variable with Values
    ProductionWorker x(employee_name, employee_number, hire_date, shift, hourly_pay);
        
    //Printing Production Worker Details
    cout << "Employee Name: " << x.employee_name << endl;
    cout << "Employee Number: " << x.employee_number << endl;
    cout << "Hire Date: " << x.hire_date << endl;
    cout << "Shift: " << x.get_Shift_Time() << endl;
    cout << "Hourly Pay: " << x.hourly_pay << endl;
        
    return 0;
}
