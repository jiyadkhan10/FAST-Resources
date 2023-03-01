//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 3

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int *number_of_votes = 0;
	int size = 0;
	int maximun = 0;
	int sum_of_votes = 0;
	
	cout << "Enter the number of Candidates participate in the Election: ";
	cin >> size;
	
	number_of_votes = new int[size];
	string* name;
	name = new string[size];
	
	cout << "Enter the name of the Candidate and their total votes: " << endl;
	
	int i = 0;
	while(i < size)
	{
		cout << "Name: ";
		cin >> name[i];
		
		cout << "Votes: ";
		cin >> number_of_votes[i];
		
		sum_of_votes += number_of_votes[i];
		
		if(number_of_votes[i] > number_of_votes[maximun])
		{
			maximun = i;
		}
		
		cout << endl;
		i++;	
	}
	cout << endl;
	
	cout << "Candidate's Name" << "\t" << "Vote Received" << "\t" << "% of Total Votes" << endl;
	
	int j = 0;
	while(j < size)
	{
		int x =(((double)number_of_votes[j]/sum_of_votes)*100);
		cout << name[j] << "\t\t\t" << number_of_votes[j] << "\t\t\t" << x << "%" << endl;
		j++;
	}
	cout << "Total Votes: " << sum_of_votes << endl;
	cout << "The winner is: " << name[maximun];
}
