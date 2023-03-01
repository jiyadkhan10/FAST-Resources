//All rights reserved by Muhammad Jiyad Khan
//Name: Muhammad Jiyad Khan
//Roll no: 19I-1771
//Sectoion BS-(D)
//Assingment # 02
//Question 3


#include <iostream>

using namespace std;

struct point_of_corrdinates
{
	int x_corrdinates;
	int y_corrdinates;
};

point_of_corrdinates sum_the_corrdinates(point_of_corrdinates &first_point, point_of_corrdinates &second_point)
{
	point_of_corrdinates third_point;
	
	third_point.x_corrdinates = first_point.x_corrdinates + second_point.x_corrdinates;
	third_point.y_corrdinates = first_point.y_corrdinates + second_point.y_corrdinates;
	
	return third_point;
}

int main()
{
	point_of_corrdinates firstpoint;
	point_of_corrdinates secondpoint;
	point_of_corrdinates thirdpoint;
	
	cout << "Enter the x-corrdinates for first point: ";
	cin >> firstpoint.x_corrdinates;
	
	cout << "Enter the y-corrdinates for first point: ";
	cin >> firstpoint.y_corrdinates;
	
	cout << "Enter the x-corrdinates for second point: ";
	cin >> secondpoint.x_corrdinates;
	
	cout << "Enter the y-corrdinates for second_point: ";
	cin >> secondpoint.y_corrdinates;
	
	thirdpoint = sum_the_corrdinates(firstpoint, secondpoint);
	
	cout << "Corrdinates of the adding two points: " << thirdpoint.x_corrdinates << "," << thirdpoint.y_corrdinates << endl;
	
	return 0;
}


