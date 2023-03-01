#include <iostream>
#include <cstring>
using namespace std;

/****************************************************************************************************/
/**********************************  Employee Class (Abstract Class) ********************************/
class Employee 
{
	public:
		
   		Employee(const char *, const char *);
   		~Employee();
		char *getFirstName() const;
		char *getLastName() const;

   		// Pure virtual functions make Employee abstract base class.
   		virtual float earnings() const = 0; // pure virtual
   		virtual void print() const = 0;     // pure virtual

	protected:
		
   		char *firstName;
   		char *lastName;
};

//Constructor
Employee::Employee(const char *first, const char *last)
{
	firstName = new char[strlen(first) + 1];
	strcpy(firstName, first);
	
	lastName = new char[strlen(last) + 1];
	strcpy(lastName, last);
}

//Destructor deallocates dynamically allocated memory
Employee::~Employee() 
{
   	delete [] firstName;   delete [] lastName;
}

//Return a pointer to the first name
char* Employee::getFirstName() const 
{
    return firstName;  //caller must delete memory
}

char* Employee::getLastName() const 
{
    return lastName;  //caller must delete memory
}

/*******************************************************************************************/
/**********************************  SalariedEmployee Class ********************************/
class SalariedEmployee: public Employee 
{
	public:
	
		SalariedEmployee(const char *, const char *, float = 0.0); //SalariedEmployee Constructor
	   	void setWeeklySalary(float); //New method added by SalariedEmployee class
	  	 virtual float earnings() const; //Own implementation of virtual funcion
	  	 virtual void print() const; //Own implementation of virtual 
	  	 
	private:
		
	   	float weeklySalary; 
};

// Constructor function for class
SalariedEmployee:: SalariedEmployee(const char *first, const char *last, float s) : Employee(first, last)  // call base-class constructor
{ 
    weeklySalary = s > 0 ? s : 0; 
}

//Set the SalariedEmployee’s salary
void SalariedEmployee::setWeeklySalary(float s) 
{ 
    weeklySalary = s > 0 ? s : 0; 
}

//Get the SalariedEmployee’s pay, NOTE: no virtual keywords here
float SalariedEmployee::earnings() const  
{ 
    return weeklySalary; 
}

// Print the SalariedEmployee’s name, NOTE: no virtual keywords here
void SalariedEmployee::print() const 
{
    cout << endl << "Salaried Employee: " << getFirstName() << ' ' << getLastName();
}


/*******************************************************************************************/
/**********************************  CommissionWorker Class ********************************/
class CommissionWorker : public Employee 
{
	public:
	
	    CommissionWorker(const char *, const char *, float = 0.0, unsigned = 0); //CommissionWorker Constructor 
	    void setCommission(float);
	    void setQuantity(unsigned);
	    virtual float earnings() const; //Own implementation of virtual funcion
	    virtual void print() const;     //Own implementation of virtual funcion

	private:
	    float commission;   // amount per item sold
	    unsigned quantity;  // total items sold for week
};

CommissionWorker::CommissionWorker(const char *first,  const char *last, float c, unsigned q) : Employee(first, last)  // call base-class constructor
{
	commission = c > 0 ? c : 0;
	quantity = q > 0 ? q : 0;
}

void CommissionWorker::setCommission(float c)
   { commission = c > 0 ? c : 0; }

void CommissionWorker::setQuantity(unsigned q)
   { quantity = q > 0 ? q : 0; }

float CommissionWorker::earnings() const //NOTE: no virtual keywords here
   { return commission * quantity; }

void CommissionWorker::print() const //NOTE: no virtual keywords here
{
   cout << endl << "Commission worker: " << getFirstName() << ' ' << getLastName();
}

/*******************************************************************************************/
/****************************************  HourlyWorker Class ******************************/
class HourlyWorker : public Employee {
public:
   HourlyWorker(const char *, const char *, 
                float = 0.0, float = 0.0);
   void setWage(float);
   void setHours(float);
   virtual float earnings() const; //Own implementation of virtual funcion
   virtual void print() const;     //Own implementation of virtual funcion

private:
   float wage;   // wage per hour
   float hours;  // hours worked for week

};

HourlyWorker::HourlyWorker(const char *first, const char *last, float w, float h) : Employee(first, last)   // call base-class constructor  
{
   wage = w > 0 ? w : 0;
   hours = h >= 0 && h < 168 ? h : 0;
}

void HourlyWorker::setWage(float w) { 
    wage = w > 0 ? w : 0; 
}

// Set the hours worked
void HourlyWorker::setHours(float h) { 
    hours = h >= 0 && h < 168 ? h : 0; 
}

// Get the HourlyWorker's pay, NOTE: no virtual keywords here
float HourlyWorker::earnings() const 
{ 
    return wage * hours; 
}

// Print the HourlyWorker's name, NOTE: no virtual keywords here
void HourlyWorker::print() const {
   cout << endl << "Hourly worker: " << getFirstName() << ' ' << getLastName();
}


/****************************************************************************************************/
/**********************************  BasePlusCommissionEmployee Class ********************************/
class BasePlusCommissionEmployee:public CommissionWorker
{
	private:
		float baseSalary;
	public:
		BasePlusCommissionEmployee(const char* , const char* , float =0.0, unsigned =0,float =0.0); //constructor

	void setBaseSalary(float sal)
	{
		baseSalary = sal;
	}
	
	float getBaseSalary(void) const 
	{	
		return baseSalary;
	}

 	void print() const;        //Own implementation of virtual funcion
 	float earnings() const;   //Own implementation of virtual funcion
};

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const char* first, const char* last, float c, unsigned q,float sal) : CommissionWorker(first,last,c,q)
{
	 baseSalary=(sal);
}

void BasePlusCommissionEmployee::print() const //NOTE: no virtual keywords here
{
	cout << "\n base-salaried commission employee: ";
	CommissionWorker::print();  // code reuse
} // end function print


float BasePlusCommissionEmployee::earnings() const //NOTE: no virtual keywords here
{ 
	return getBaseSalary() + CommissionWorker::earnings(); 
} // end function earnings


/*****************************************************************************************/
/*****************************************************************************************/
int main()
{
    Employee *ptr;  // base-class pointer
    //ptr = new Employee("Ali","Khan"); //ERROR: Cannot create object of Abstract class
    
    SalariedEmployee b("Nauman", "Sarwar", 800.00); // first name, last name, weekly salary
    ptr = &b;                                       // base-class pointer to derived-class object
    ptr->print();                                   // dynamic binding
    cout << " earned $" << ptr->earnings();         // dynamic binding
    b.print();                                      // static binding
    cout << " earned $" << b.earnings()<<endl<<endl;// static binding


    CommissionWorker c("Qasim", "Ali", 3.0, 150);   // first name, last name, weekly salary, commision, quantity
    ptr = &c;                                       // base-class pointer to derived-class object
    ptr->print();                                   // dynamic binding
    cout << " earned $" << ptr->earnings();         // dynamic binding
    c.print();                                      // static binding
    cout << " earned $" << c.earnings() <<endl<<endl;// static binding

   
    BasePlusCommissionEmployee p("Mehshan", "Mustafa", 2.5, 200, 1000.0); //first name, last name, weekly salary, commision, quantity, base salary
    ptr = &p;                                       // base-class pointer to derived-class object
    ptr->print();                                   // dynamic binding
    cout << " earned $" << ptr->earnings();         // dynamic binding
    p.print();                                      // static binding
    cout << " earned $" << p.earnings() <<endl<<endl;//static binding


    HourlyWorker h("Samer", "Tufail", 13.75, 40); // first name, last name, wage, hours
    ptr = &h;                                     // base-class pointer to derived-class object
    ptr->print();                                 // dynamic binding
    cout << " earned $" << ptr->earnings();       // dynamic binding
    h.print();                                    // static binding
    cout << " earned $" << h.earnings();          // static binding
    
    cout << endl;
    return 0;
}
