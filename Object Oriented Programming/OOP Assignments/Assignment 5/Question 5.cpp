//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 5
//Q5


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

class TimeClock : public MilTime
{
	private:
	    int start_time;              // Member variable to store start time.
	    int end_time;                // Member variable to store end time.
        
	public :
		
		//Setters and Getters
    	bool set_start_time(int s_time)               
    	{
    	    if(s_time < 0 || s_time > 2359)
    	    {
    	        cout << "Start time should be between 0000 hours to 2359 hours" << endl;
    	        return false;
    	    }
    	    
    	    if(s_time % 100 >= 60)
    	    {
    	        cout << "Invalid input in 24 hours format" << endl;
    	        return false;
    	    }
    	    
    	    start_time = s_time;
    	    
    	    return true;
    	}
    	
    	bool set_end_time(int e_time)                 
    	{
    	    if(e_time < 0 || e_time > 2359)
    	    {
    	        cout << "End time should be between 0000 hours to 2359 hours" << endl;
    	        return false;
    	    }
    	    
    	    if(e_time % 100 >= 60)
    	    {
    	        cout << "Invalid input in 24 hours format" << endl;
    	        return false;
    	    }
    	    
    	    end_time = e_time;
    	    
    	    return true;
    	}
    	
    	int get_start_time()                      
    	{
    	    return start_time;
    	}
    	
    	int get_end_time()                        
   		{
    	   return end_time;
    	}
    	
    	int timeLapse()                       
    	{
        	int start_time_minute = (start_time % 100 + (start_time / 100) * 60);
       		int end_time_minute = (end_time % 100 + (end_time / 100) * 60);
       		return (end_time_minute - start_time_minute);
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
	int start_time;
	int end_time;
	
	string clock;
	
	cout << "Enter Hours in military format: ";
	cin	>> time_h;
	
 	cout << "Enter Hours in military format: ";
	cin >> time_m;
	
	cout << "Enter Hours in military format: ";
	cin >> time_s;
	
	cout << endl;
	
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
	
	cout << "Time in militray format is: " << time_h << time_m << " Hrs " << endl;
	
	cout << endl;
	
	Time xx(time_h, time_m, time_s);
	MilTime yy;
	yy.setTime(time_h, time_m, time_s);
	
	x = yy.getStandHr(time_h);
	y = xx.getMin();
	z = xx.getSec();
	
	if(time_h >= 12)
	{
		clock = "PM";
	}
	
	if(time_h <= 12)
	{
		clock = "AM";
	}
	
	cout <<"Time in standard format is: " << x << ":" << y << ":" << z << " " << clock << endl;
	
	cout << endl;

    TimeClock time_clock;
    
    cout << "Enter start time: ";
    cin >> start_time;
    
    time_clock.set_start_time(start_time);
    
    cout << "Enter end time: " ;
    cin >> end_time;
  	
  	time_clock.set_end_time(end_time);
  	
  	// Print time lapse in hours and minutes format.
    cout << "Time Lapse: " << (time_clock.timeLapse() / 60) << " Hours " << (time_clock.timeLapse() % 60) << " Mins" << endl;   
}


