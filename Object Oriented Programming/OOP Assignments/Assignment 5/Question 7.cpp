//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 5
//Q7


#include <iostream>
#include <string>

using namespace std;

class PersonData
{
	private:
	
		// Member Variables
    	string first_name;
    	string last_name;
    	string address;
    	string city_name;
    	string state_name;
    	string phone_number;
    	string zip_code;
    	
	public:
		
		// Default Constructor
        PersonData()
		{
            this->first_name = " ";
            this->last_name = " ";
            this->address = " ";
            this->city_name = " ";
            this->state_name = " ";
            this->phone_number = " ";
            this->zip_code = " ";
        }
        
        // Parameterized constructor
        PersonData(string f_name, string l_name, string a, string c_name, string s_name, string p_number, string z_code)
		{
            this->first_name = f_name;
            this->last_name = l_name;
            this->address = a;
            this->city_name = c_name;
            this->state_name = s_name;
            this->phone_number = p_number;
            this->zip_code = z_code;
        }
        
    	// Setter Methods
    	void set_first_name(string f_name)
    	{
        	first_name = f_name;
    	}
    	
    	void set_last_name(string l_name)
    	{
        	last_name = l_name;
    	}
    	
	    void set_address(string a)
    	{
    	    address = a;
    	}
    	
    	void set_city_name(string c_name)
    	{
    	    city_name = c_name;
    	}
    	
    	 void set_state_name(string s_name)
    	{
    	    state_name = s_name;
    	}
    	
     	void set_zip_code(string z_code)
    	{
    	    zip_code = z_code;
    	}
    	
     	void set_phone_number(string p_number)
    	{
    	    phone_number = p_number;
    	}
    	
    	// Getter Methods
    	string get_first_name()
    	{
    	    return first_name;
    	}
    	
    	string get_last_name()
    	{
       		return last_name;
   	 	}
   	 	
    	string get_address()
    	{
        	return address;
    	}
    	
    	string get_city_name()
    	{
    	   return city_name;
    	}
    	
    	string get_state_name()
    	{
    	   return state_name;
    	}
    	
    	string get_zip_code()
    	{
    	   return zip_code;
    	}
    	
    	string get_phone_number()
    	{
    	   return phone_number;
    	}
    	
};	

class CustomerData: public PersonData      .
{
	private:
	             
    	string customer_number;
    	char mailing_list;
    	
	public:
		
		// Default Constructor
        CustomerData()
		{
            this->customer_number = " ";
            this->mailing_list = false;
        }
        
        // Parameterized Constructor
        CustomerData(string f_name, string l_name, string a, string c_name, string s_name, string p_number, string z_code, string c_number, bool m_list): PersonData(f_name, l_name, a, c_name, s_name, p_number, z_code)
		{
                customer_number = c_number;
                this->mailing_list = m_list;
        }
		
    	void set_customer_number(string c_number)
    	{
    	    customer_number = c_number;
    	}
    	
    	void set_mailing_list(char m_list)
    	{
    	    mailing_list = m_list;
    	}
    	
    	string get_customer_number()
    	{
    	    return customer_number;
    	}
    	
    	char get_mailing_list()
    	{
    	    return mailing_list;
    	}
    	
    	bool get_mailing_list_x()
    	{
    		if(mailing_list == 'y' || mailing_list == 'Y')
    		{
    			return true;
			}
			
			else if(mailing_list == 'n' || mailing_list == 'N')
    		{
    			return false;
			}
			
			else
			{
				cout << "Invalid Input!!!!!!!" << endl;
				return false;
		 	}
		}
};

class PreferredCustomer: public CustomerData 
{
    private:
    	
        double purchase_amount;
        double discount_level;
        double discount_price;
        
    public:
    	
        // Default constructor
        PreferredCustomer()
		{
            purchase_amount = 0.0;
            discount_level = 0.0;
        }
        
        // Parameterized constructor
        PreferredCustomer(string f_name, string l_name, string a, string c_name, string s_name, string p_number, string z_code, string c_number, bool m_list, double amount): 
		CustomerData(f_name, l_name, a, c_name, s_name, p_number, z_code, c_number, m_list)
		{ 
            if(amount < 0)
            {
                amount = 0;
            }
            
            this->purchase_amount = amount;
            set_discount();
        }
        
        //Setters and Getters
        void set_amount(double a)
		{
            if(a >= 0)
            {
                purchase_amount = a;
            }
        }
        
        //Method to set Discount level
		void set_discount()
		{
			if (get_amount() >= 2000)
			{
				discount_level = 10;
			}
			
			else if (get_amount() >= 1500)
			{
				discount_level = 7;
			}
			
			else if (get_amount() >= 1000)
			{
				discount_level = 6;
			}
			
			else if(get_amount() >= 500)
			{
				discount_level = 5;
			}
			
			else
			{
				discount_level = 0;
			}
		}
        
       double get_amount()
		{
            return purchase_amount;
        }
		
		double get_discount()
		{
			set_discount();
			return discount_level;
		}
		
		void set_discount_price_x()
        {
            discount_price = get_amount() - (get_amount() * (get_discount() / 100));
        }
        
        double get_discount_price()
        {
        	set_discount_price_x();
			return 	discount_price;
		}
		
		void set_discount_price(double discountprice)
		{
			this->discount_price = discountprice;
		}
        
        
		
};
	            
int main()
{
	string customer_number;
	string first_name;
	string last_name;
	string address;
	string city_name;
	string state_name;
	string zip_code;
	string phone_number;
	char mailing_list;
	double amount;
	
	CustomerData x;
	PreferredCustomer y;
	
	cout << "Enter the first name: ";
    getline(cin, first_name);
   	
   	x.set_first_name(first_name);
        	
    cout << "Enter the last name: ";
    getline(cin, last_name);
    
    x.set_last_name(last_name);
    
    cout << "Enter the Customer Number: ";
	getline(cin, customer_number);
   	
   	x.set_customer_number(customer_number);
        	
   	cout << "Enter the address: ";
    getline(cin, address);
    
    x.set_address(address);
    	
    cout << "Enter the city name: ";
    getline(cin, city_name);
    
	x.set_city_name(city_name);
		    
    cout << "Enter state name: ";
    getline(cin, state_name);
    
    x.set_state_name(state_name);
    
    cout << "Enter the zip code: ";
    getline(cin, zip_code);

    x.set_zip_code(zip_code);
    	    
    cout << "Enter the phone number: ";
    getline(cin, phone_number);
	
	x.set_phone_number(phone_number);
	
	cout << "Do you want to be on mailing list (y/n)? ";
    cin >> mailing_list;
    
    x.set_mailing_list(mailing_list);
    
    cout << "Enter the purchase amount: ";
    cin >> amount;
    
    y.set_amount(amount);
    
    cout << endl;
    
    //Displaying the Preferred Customer Details
    cout << "-------- Preferred Customer Details --------" << endl;
    
    cout << endl;
    
    cout << "Customer's Number: " << x.get_customer_number() << endl;
    cout << "First Name: " << x.get_first_name() << endl;
    cout << "Last Name: " << x.get_last_name() << endl;
    cout << "Address: " << x.get_address() << endl;
    cout << "City Name: " << x.get_city_name() << endl;
    cout << "State Name: " << x.get_state_name() << endl;
    cout << "Zip Code: " << x.get_zip_code() << endl;
    cout << "Phone Number: " << x.get_phone_number() << endl;
    cout << "Is customer on mailing list: " << x.get_mailing_list_x() << endl;
    cout << "Purchase Amount: $" << y.get_amount() << endl;
	cout << "Discount on further purchase: " << y.get_discount() << "%" << endl;
	cout <<  "Discount Price: $" << y.get_discount_price() << endl;
    
    return 0;
}
