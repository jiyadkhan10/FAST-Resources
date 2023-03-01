//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 3
//Q2


#include <iostream>
#include <iomanip>

using namespace std;

struct Car
{
	private: //private data member
		float current_fuel;
		float fuel_efficiency;
	
	public:
		
		Car() //default constructor
		{
			fuel_efficiency = 0;
		    current_fuel = 0;
		}
		
		Car(float efficiency) //parametized constructor
		{
			if(efficiency > 0)
			{
				fuel_efficiency = efficiency;
	        	current_fuel = 0;
			}
		}
		
		float getFuelLevel() //return the current fuel
		{
			return current_fuel;
		}
		
		void tank(float fuels_in_liters) // adding the fuel into the current fuel
		{
			current_fuel = current_fuel + fuels_in_liters;
		}
		
		void drive(float distance) //Current fuel after travelling some distance
		{
			current_fuel -= (distance / fuel_efficiency);
		}
		
		void main() //Sample usage of the structure
        {
	        Car myBeemer(29);
	
        	cout << fixed << setprecision(1) << myBeemer.getFuelLevel() << endl;
	
         	myBeemer.tank(20);
	
        	cout << myBeemer.getFuelLevel() << endl;
	
        	myBeemer.drive(100);
	
     	    cout << fixed << setprecision(15) <<myBeemer.getFuelLevel() << endl;
        }
		
};

int main()
{
	Car x;
	
	x.main();
}
