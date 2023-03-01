//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 3
//Q8

#include <iostream>
#include <iomanip>

using namespace std;

class Student // class student
{
	private: //private data members
		
		char *Name;
		char *Roll_Number;
		int Batch;
		int Courses_Code[5];
		char *Courses_Name[5];
		char Courses_Grades[5];
		float CGPA;
		char *Degree;
		char *Date_of_Birth;
	
	public: //declarations and defining of all constructors and function
		
		Student() //default constructor
		{
			Name = new char[100];
			Roll_Number = new char[100];
			Batch = 0;
			
			int i = 0;
			while(i < 5)
			{
				Courses_Code[i] = 0;
				Courses_Name[i] = new char[100];
				Courses_Grades[i] = '\0';
				
				i++;
			}
			CGPA = 0.0;
			Degree = new char[100];
			Date_of_Birth = new char[100];
		}
		
		Student(char *n, char *rollnumber, int batch, int c_code[5], char *c_name[5], char c_grades[5], float cgpa, char *degree, char *date_of_birth) //parameterized constructor
		{
			Name = n;
			Roll_Number = rollnumber;
			Batch = batch;
			
			int i = 0;
			while(i < 5)
			{
				Courses_Code[i] = c_code[i];
				Courses_Name[i] = c_name[i];
				Courses_Grades[i] = c_grades[i];
				
				i++;
			}
			CGPA = cgpa;
			Degree = degree;
			Date_of_Birth = date_of_birth;
		}
		
		void set_values(char *n, char *rollnumber, int batch, int c_code[5], char *c_name[5], char c_grades[5], float cgpa, char *degree, char *date_of_birth) //set values through  passed arguments
		{
			Name = n;
			Roll_Number = rollnumber;
			Batch = batch;
			
			int i = 0;
			while(i < 5)
			{
				Courses_Code[i] = c_code[i];
				Courses_Name[i] = c_name[i];
				Courses_Grades[i] = c_grades[i];
				
				i++;
			}
			CGPA = cgpa;
			Degree = degree;
			Date_of_Birth = date_of_birth;
		}
		
		void set_values() //set values by users
		{
			cout << "Enter the name: ";
			cin.getline(Name, 100);
			
			cout << "Enter the roll number: ";
			cin >> Roll_Number;
			
			cout << "Enter the batch number: ";
			cin >> Batch;
			
			int i = 0;
			while(i < 5)
			{
				cout << "Course " << (i + 1) << ": " << endl;
				
				cout << "Enter the course code: ";
				cin >> Courses_Code[i];
				
				cout << "Enter the course name: ";
				cin >> Courses_Name[i];
				
				cout << "Enter the course grade: ";
				cin >> Courses_Grades[i];
				fflush(stdin);
				
				i++;
			}
			
			cout << "Enter CGPA: ";
			cin >> CGPA;
			
			cout << "Enter the degree's name: ";
			cin.getline(Degree, 100);
			
			cout << "Enter your Date of Birth: ";
			cin >> Date_of_Birth;
		}
		
		//updating the method
		
		void update_name(char *n)
		{
			Name = n;
		}
		
		void update_Roll_Number(char *roll_number)
		{
			Roll_Number = roll_number;
		}
		
		void update_Batch(int batch)
		{
			Batch = batch;
		}
		
		void update_Courses_Code(int courses_code[5])
		{
			int i = 0;
			while(i < 5)
			{
				Courses_Code[i] = courses_code[i];
				i++;
			}
		}
		
		void update_Courses_Name(char *courses_name[5])
		{
			int i = 0;
			while(i < 5)
			{
				Courses_Name[i] = courses_name[i];
				i++;
			}
		}
		
		void update_Courses_Grades(char courses_grades[5])
		{
			int i = 0;
			while(i < 5)
			{
				Courses_Grades[i] = courses_grades[i];
				i++;
			}
		}
		
		void update_CGPA(float cgpa)
		{
			CGPA = cgpa;
		}
		
		void update_Degree(char *degree)
		{
			Degree = degree;
		}
		
		void update_Date_of_Birth(char *date_of_birth)
		{
			Date_of_Birth = date_of_birth;
		}
		
		void display() // display the method
		{
			cout << "Name: " << Name << endl;
			cout << "Roll Number: " << Roll_Number << endl;
			cout << "Batch: " << Batch << endl;
			
			cout << "|----------------------------------------------------------------------------------------------|" << endl;
			
			cout << "|" << setw(20) << "Course Code" << setw(20) << "Course Name" << setw(20) << "Course Grades |" << endl;
			
			int i = 0;
			while(i < 5)
			{
				cout << "|" << setw(20) << Courses_Code[i] << setw(20) << Courses_Name[i] << setw(20) << Courses_Grades[i] << "|" << endl;
				i++;
			}
			
			cout << "|----------------------------------------------------------------------------------------------|" << endl;
			
			cout << setw(16) << "CGPA: " << setw(15) << CGPA << endl;
			cout << setw(16) << "Degree's Name: " << setw(15) << Degree << endl;
			cout << setw(16) << "Date of Birth: " << setw(15) << Date_of_Birth << endl; 
		}
};

void Student_Demo() //Demo
{
	Student x;
	x.set_values();
	x.display();
}

int main()
{
	Student_Demo();
}
