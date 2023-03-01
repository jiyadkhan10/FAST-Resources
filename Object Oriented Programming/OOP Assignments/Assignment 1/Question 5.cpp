//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 5

#include <iostream>

using namespace std;

int main()
{
  cout << "Enter any negative value to exist" << endl;
  while(true)
  {

	float *amount_of_rupees = new float;
	
	cout << "Enter the amount in the Pakistani's Rupees: ";
	cin >> *amount_of_rupees;
	
	if (*amount_of_rupees < 0)
	{
		break;
	}
	
	cout << *amount_of_rupees << "Pakistani Rupees: ";
	*amount_of_rupees = (*amount_of_rupees)* 0.041;
	cout << *amount_of_rupees << " Chinese Yuan" << endl;
	
  }
  
}
