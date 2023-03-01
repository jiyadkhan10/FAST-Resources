//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 3
//Q4


#include <iostream>

using namespace std;

struct FlightInfo
{
	private: //private data member
		
		int FlightNumber;
		char *Destination;
		float Distance;
		float Fuel;
		
		void calFuel(float distance) //calculate the value of Fuel
		{
			if (distance > 0)
			{
				if (distance <= 1000)
			    {
				     Fuel = 500;
			    }
			    else if (distance > 1000 && distance <= 2000)
			    {
				     Fuel = 1100;
			    }
			    else
			    {
				    Fuel = 2200; 
			    }
			}
		}
	
	public:
		
		void feedInfo() // Feeding the information
		{
			cout << "Please Enter your Flight Number: ";
		    cin >> FlightNumber;
			
			Destination = new char[100];
			
			cout << "Please Enter your Destination: ";
	        cin.ignore();
			cin.getline(Destination, 100); 
			
			cout << "Please Enter the Distance: ";
			cin >> Distance;
			
			calFuel(Distance);
		}
		
		void showInfo() // Shwing the information
		{
			cout << "Flight Number: " << FlightNumber << endl;
			cout << "Destination: " << Destination << endl;
			cout << "Distance: " << Distance << endl;
			cout << "Fuel: " << Fuel << endl;
		}
		
		float getFuel()
		{
			return Fuel;
		}
};

int main()
{
	FlightInfo x;
	
	x.feedInfo();
	x.showInfo();
}
