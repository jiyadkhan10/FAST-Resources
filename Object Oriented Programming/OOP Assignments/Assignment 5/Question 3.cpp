//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 5
//Q3


#include <iostream>
#include <iomanip>
#include <string>

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
        	
        	// Setters and Getters
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
 
class ProductionWorker: public Employee 
{  
    public:
    	
        //ProductionWorker variables   
        int shift;
        double hourly_pay;
        
        ProductionWorker()
        {
			shift = 0;
			hourly_pay = 0.0;                 
        }
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

class TeamLeader:public ProductionWorker
{
	private:
	 
		double monthly_bonus;
        int time_required_hours;   //variable to hold number of training hours required
        int time_attend_hours;	   //variable to hold number of training hours attended
        
	public:
	 
		//Default constructors
        TeamLeader()
      	{
            monthly_bonus = 0.0;
            time_required_hours = 0;
            time_attend_hours = 0;
        }
        
        //Parameterized constructors
        TeamLeader(double m_bonus,int r_hours,int a_hours)
        {
        	monthly_bonus = m_bonus;
          	time_required_hours = r_hours;
          	time_attend_hours = a_hours;
        }
        
        void set_monthly_bonus(double m_Bonus)
        {
           	monthly_bonus = m_Bonus;
		}
		
        void set_time_required_hours(int r_hours)
        {
          	time_required_hours = r_hours;
		}
		
        void set_time_attend_hours(int a_hours)
        {
          	time_attend_hours = a_hours;
		}
		
        double get_monthly_bonus()
        {
          	return monthly_bonus;
		}
		
        int get_time_required_hours()
        {
          	return time_required_hours;
		}
		
        int get_attend_hours()
        {
          	return time_attend_hours;
		}
};

int main()
{
    TeamLeader x;
	
	string employee_name;
	string hire_date;
    int employee_number;
	int shift;
	int time_required_hours;
	int time_attend_hours;
	double montly_bonus;
    double hourly_pay;
        
    //Taking the Worker Details
    cout << "Enter Employee Name: ";
    getline(cin, employee_name);
    
    x.set_Employee_name(employee_name);
    
    cout << "Enter Employee Number: ";
    cin >> employee_number;
    
    x.set_Employee_number(employee_number);
    
    cout << "Enter Hire Date: ";
    cin >> hire_date;
    
    x.set_hire_date(hire_date);
    
    cout << "Enter Shift 1-Day / 2-Night: ";
    cin >> shift;
    
    x.set_Shift(shift);
    
    cout << "Enter Hourly Pay: ";
    cin >> hourly_pay;
    
    x.set_Hourly_pay(hourly_pay);
     
    cout << "Enter Montly Bonus: ";
    cin >> montly_bonus;
    
    x.set_monthly_bonus(montly_bonus);
     
    cout << "Enter Required Hours: ";
    cin >> time_required_hours;
     
    x.set_time_required_hours(time_required_hours);
     
    cout << "Enter Attended Hours: ";
    cin >> time_attend_hours;
     
    x.set_time_attend_hours(time_attend_hours);
    
    cout << endl;
     
    //Outputting Data
    cout << "-----Team Lead Details-----" << endl;
    
    cout << endl;
    
    cout << "Name:" << x.get_Employee_name() << endl;
    cout << "EmpNumber: " << x.get_Employee_number() <<endl;
    cout << "HireDate: " << x.get_hire_date() << endl;
    cout << "Shift: " << x.get_Shift_Time() << endl;
    cout << "Hourly Pay: $" << x.get_Hourly_pay() << endl;
    cout << "Monthly Bonus: $" << x.get_monthly_bonus() << endl;
    cout << "Required Training Hours: " << x.get_time_required_hours() << " hrs " << endl;
    cout << "Attended Training Hours: " << x.get_attend_hours() << " hrs " << endl;
	
	return 0;    
}
