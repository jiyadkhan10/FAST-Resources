//All rights reserved by Muhammad Jiyad Khan
//Name: Muhammad Jiyad Khan
//Roll no: 19I-1771
//Sectoion BS-(D)
//Assingment # 02
//Question 4


#include <iostream>
#include <cstring>

using namespace std;

struct time
{
	int hours;
	int minutes;
	int seconds;
	
	void Print_in_seconds()
	{
		int total_seconds;
		
	    total_seconds = (hours * 3600) + (minutes * 60) + (seconds);
	    cout << "Your given time in seconds: " << total_seconds << endl;
	}
};

time tokenize_the_string(string Time)
{
	time t;
    int hour1;
    int hour2;
    int hour;
    
    hour1 = Time[1]-'0';
    hour2 = Time[0]-'0';
    hour = (hour2 * 10 + hour1 % 10);
    
    t.hours = hour;
    
    int i = 3;
    int x = 0;
	int y = 0;
    
    while(i <= 7)
    {
        
		if(i == 3)
		{
			x = x*10 + (Time[i]-'0');
		}   	
    	
    	else if(i == 4)
		{
			x = x*10 + (Time[i]-'0');
		} 
		
		else if(i == 6)
		{
			y = y*10 + (Time[i]-'0');
		} 
		
		else if(i == 7)
		{
			y = y*10 + (Time[i]-'0');
		} 
    	
    	i++;
	}
	
	t.minutes = x;
	t.seconds = y;
	
	return t;	
}

int main()
{
	string s;
	time string;
	
	cout << "Enter the time in the format of (hh:mm:ss): ";
	getline(cin, s);
	
	string = tokenize_the_string(s);	
	string.Print_in_seconds();
	
	return 0;	
}


