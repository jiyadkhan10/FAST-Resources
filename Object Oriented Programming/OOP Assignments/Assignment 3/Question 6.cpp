//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 3
//Q6

#include <iostream>

using namespace std;

class Address
{
	
	public:
		
		int HouseNumber;
        int street;
	    int ApartmentNumber;
     	char* city;
    	char* state;
	    int PostalCode;
	
	    // constructor with apartment number
	
	    Address(int houseNumber, int st, char *c, char *s, int p, int apartmentnumber) 
	    {
		    ApartmentNumber = apartmentnumber;
		    HouseNumber = houseNumber;
		    street = st;
		    city = c;
		    state = s;
		    PostalCode = p;
	    }
	
	    // constructor without apartment number
	
	    Address(int houseNumber, int st, char *c, char *s, int p) 
	    {
		    HouseNumber = houseNumber;
		    street = st;
		    city = c;
		    state = s;
		    PostalCode = p;
	    }
	
	    void print() // print address with street on one line and city, state and postal code on the next line
	    {
		    cout << "Street: " << street  << endl;
		    cout << "City: " << city << "\t State: " << state << "\t Postal Code: " << PostalCode << endl;
    	}
	
	    bool compareTo(Address const other_postal_code) // compare whether one address comes before another when the addresses are compared by postal code
    	{
	    	if (PostalCode < other_postal_code.PostalCode)
	    	{
		    	return true;
	    	}
		
		    else
		    {
	    		return false;
	    	}		
	    }
	
};



int main()
{
	cout << "First Address: " << endl; //Address class with apartment number
	
	cout << endl;
	
	Address first_address(220, 10, "Islamabad", "Punjab", 100201, 2);
	
	first_address.print();
	
	cout << endl;
	
	cout << "Second Address: " << endl; //Address class without apartment number
	
	cout << endl;
	
	Address second_address(100, 25, "Karachi", "Sindh", 100450);
	
	second_address.print();
	
	cout << endl;
	
	cout << "Comparing: " << first_address.compareTo(second_address) << endl;
	
	
	
	
}
