//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 5
//Q8


#include<iostream>

using namespace std;

class GradedActivity
{
	protected:
		
		double score;
		
	public:
		GradedActivity()
		{
			score = 0.0;
		}
		GradedActivity(double s)
		{
			score = s;
		}
		void setScore(double s)
		{
			score = s;
		}
		double getScore()
		{
			return score;
		}
		char getLetterGrade()
		{
			//Calculating Grade
			if(score >= 80)
			{ 
				return 'A';
			}
			
			else if(score >= 70 && score < 80)
			{
				return 'B';
			}
			
			else if(score >= 60 && score < 70)
			{
				return 'C';
			}
			
			else if(score >= 50 && score < 60)
			{
				return 'D';
			}
			
			else if(score >= 40 && score < 50)
			{
				return 'E';
			}
			
			else
			{
				return 'F';
			}
			
		}
};

class Essay:public GradedActivity
{
	public:
	
		int grammar;
		int spelling;
		int correct_length;
		int content;
		
		Essay(int g,int s,int c_length,int c) //parameterized constructor to initialize the variables
		{
			grammar = g;
			spelling = s;
			correct_length = c_length;
			content = c;
		}

};

int main()
{
	double grammar;
	double spelling;
	double correct_length;
	double content;
	
	cout << "Enter marks for grammar(out of 30): ";
	cin >> grammar;
	
	cout << "Enter marks for spelling(out of 20): ";
	cin >> spelling;
	
	cout << "Enter marks for correct length(out of 20): ";
	cin >> correct_length;
	
	cout << "Enter marks for content(out of 30): ";
	cin >> content;
	
	if(grammar <= 30 && spelling <= 20 && correct_length <= 20 && content <= 30)
	{
		//Create an Object
		Essay x(grammar, spelling, correct_length, content); 
		
		//Set Score
		x.setScore(grammar + spelling + correct_length + content); 
		
		cout << "Total Score: " << x.getScore() << endl; 
		cout << "Grade: " << x.getLetterGrade() << endl; 
	}
	
	else
	{
		//Invalid Inputs
		cout << "Invalid inputs(check the maximum limit:Grammar-30,Spelling-20,Correct length-20,Content-30)" << endl;
	}
}
