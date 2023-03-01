//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 5
//Q4


#include <iostream>

using namespace std;

class Time
{
	protected :
		
		int hour;
		int min;
		int sec;
		
	public:
		
		//Default constructor
		Time()
		{
			hour = 0; min = 0; sec = 0;
		}
		
		//Constructor
		Time(int h, int m, int s)
		{
			hour = h; min = m; sec = s;   
		}
		
		//Accessor function
		int getHour()
		{
			return hour;
		}
		
		int getMin()
		{
			return min;
		}
		
		int getSec()
		{
			return sec;
		}
};

class MilTime: public Time
{
	public:
		
		int milHours;
		int milSeconds;
		
		//Parameterized Constructor
		MilTime(int h, int m, int s)
		{
			if(h >= 13 && h <= 24 && m >= 0 && m <= 60 && s >= 0 && s <= 60)
			{
				h = h - 12;
				hour = h;
				min = m;
				sec = s;
			}
			
			else if(h > 0 && h <= 12 && m >= 0 && m <= 60 && s >= 0 && s <= 60)
			{
				hour = h;
				min = m;
				sec = s;
			}
			
			else if(h == 0 && m >= 0 && m <= 60 && s >= 0 && s <= 60)
			{
				h = h + 0;
				hour = h;
				min = m;
				sec = s;
			}
			
			else
			{ 
				cout << "Wrong Entry!!!!!!!" << endl;
				exit(0);   
			}
		}

		int setTime(int h,int m,int s)
		{
			if(h >= 13 && h <= 24 && m >= 0 && m <= 60 && s >= 0 && s <= 60)
			{
				h = h - 12;
				hour = h;
				min = m;
				sec = s;
			}
			
			else if(h > 0 && h <= 12 && m >= 0 && m <= 60 && s >= 0 && s <= 60)
			{
				hour = h;
				min = m;
				sec = s;
			}
			
			else if(h == 0 && m >= 0 && m <= 60 && s >= 0 && s <= 60)
			{
				h = h + 0;
				hour = h;
				min = m;
				sec = s;
			}
			
			else
			{ 
				cout << "Wrong Entry!!!!!!!" << endl;
				exit(0);   
			}
			
			return 0;
		}
		
		int getHour(int h)
		{
			return h;
		}
		
		int getStandHr(int h)
		{
			if(h >= 13 && h <= 24)
			{
				h = h-12;
				return h;
			}
			
			if(h > 0 && h <= 12)
			{
				hour = h;
				return h;
			}
			
			if(h == 0)
			{
				h = h + 0;
				return h;
			}   
		}
  
};

int main()
{
	int time_h;
	int time_m;
	int time_s;
	
	int x;
	int y;
	int z;
	
	string clock;
	
	cout << "Enter Hours in military format: ";
	cin	>> time_h;
	
 	cout << "Enter Hours in military format: ";
	cin >> time_m;
	
	cout << "Enter Hours in military format: ";
	cin >> time_s;
	
	if(time_h >= 24 && time_m >= 60)
	{
		cout << "Wrong Entry!!!!!!!" << endl;
		exit(0);
	}
	
	if(time_h == 0 && time_m == 0)
	{
		cout << "Wrong Entry!!!!!!!" << endl;
		exit(0);
	}
	
	cout << endl;
	
	cout << "Time in militray format is: " << time_h << time_m << " Hrs. " << endl;
	
	Time first_time(time_h, time_m, time_s);
	MilTime second_time(time_h, time_m, time_s);
	second_time.setTime(time_h, time_m, time_s);
	
	x = second_time.getStandHr(time_h);
	y = first_time.getMin();
	z = first_time.getSec();
	
	if(time_h >= 12)
	{
		clock = "PM";
	}
	
	if(time_h <= 12)
	{
		clock = "AM";
	}
	
	cout << endl;
	
	cout <<"Time in standard format is: " << x << ":" << y << ":" << z << " " << clock << endl;
	
	return 0;
}


