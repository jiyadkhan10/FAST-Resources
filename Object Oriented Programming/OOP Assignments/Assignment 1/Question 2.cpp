//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 2


#include <iostream>

using namespace std;

int Seat_Occupied(char array[10][5])
{
	int x = 0;
	int i = 0;
	int j = 0;
	
	while (i < 10)
	{
		while (j < 5)
		{
			if(array[i][j] == 'X')
			{
				x++;
			}
			j++;
		}
		i++;
	}
	
	if(x == 40)
	{
		return 1;
	}
	
	return 0;
}

void display_the_seat(char array[10][5])
{
    int i = 0;
    while(i < 10)
    {
     	for(int j = 0; j < 5; j++)
     	{
     		cout<< array[i][j] << " ";
	    }
		
		cout << endl;
		i++;
	}
       
	return ;
}

string data_of_user()
{
	string x;
	
	cout << "Enter the valid seat number of the seat (like 1B): ";
	cin >> x;
	
	return x;
}

void update_the_seat(char array[7][5], int r, int c)
{
	cout << "Your seat is valid. Now, Reserved for you." << endl;
	cout << "Updated the Seat Avaiable" << endl;
	
	array[r][c] = 'X';
}

int check_the_seat(char array[10][5], string x)
{
	if(x[0] >'10' || x[0] < '1' || x[1] < 'A' || x[1] > 'D')
	{
		cout << "Invalid Seat" << endl;
		return 0;
	}
	
	int r = -1, c = -1;
	
	int i = 0;
	while(i < 10)
	{
		if(array[i][0] == x[0])
		{
			r = i;
		}
		i++;
	}
	int j = 0;
	while(j < 5)
	{
		if(array[r][j] == x[1])
		{
			c = j;
		}
		j++;
	}
	
	if (c == -1)
	{
		cout << "Seat is already taken" << endl;
		return 0;
	}
	else
	{
		update_the_seat(array, r, c);
	}
	
	return 1;
}

void Continue_for_taking_seat(char array[10][5])
{
	cout << "Enter Z if you are done taking the seat! ";
	
	string x;
	
	while(true)
	{
		x = data_of_user();
		
		if(x[0] == 'Z')
		{
			break;
		}
		
		if(check_the_seat(array, x))
		{
			display_the_seat( array);
		}
		
		if(Seat_Occupied(array))
		{
			cout << "Sorry! No more seat is avaiable." << endl;
			break; 
		}
	}
	cout << "Thank You!!!!!!" << endl;
}

int main()
{
	char array[10][5];
	
	int i = 0;
    while(i < 10)
    {
     	array[i][0] = i+1+'0';
     	
     	for(int j = 1; j < 5; j++)
     	{
     		array[i][j] = 'A'+j-1;
		}
		
		i++;
	}
		
	cout << "Current Seat Arrangements!!!!!!" << endl;
	display_the_seat(array);
	
	Continue_for_taking_seat(array);
	
	return 0;
}
