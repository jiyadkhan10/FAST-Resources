//Name: Jiyad Khan
//Roll No: 19I-1771
//Question 1 part v

#include <iostream>

using namespace std;

void Display_the_Planets()
{
	char *name_of_the_planets[8] = {"Mercury", "Venus","Earth","Mars","Saturn","Jupiter","Uranus","Neptune"};
	
	int i = 0;
	while (i < 8)
	{
		
		cout <<  *(name_of_the_planets + i) << endl;
		i++;
	}
}

int main()
{
	Display_the_Planets();
	return 0;
}
	


