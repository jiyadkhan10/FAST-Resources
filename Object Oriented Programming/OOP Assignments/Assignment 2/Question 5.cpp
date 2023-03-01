//All rights reserved by Muhammad Jiyad Khan
//Name: Muhammad Jiyad Khan
//Roll no: 19I-1771
//Sectoion BS-(D)
//Assingment # 02
//Question 5

#include<iostream>
#include<string>

using namespace std;

struct Text_Editor
{
	string inserted_text;
	unsigned int chracters_count;
	unsigned int words_count;
	unsigned int redundant_words;
	
	Text_Editor()
	{
		inserted_text = " ";
		chracters_count = 0;
		words_count = 0;
		redundant_words = 0;
	}
	
	void insert_text()
	{
		cout<<"Enter text: ";
		getline (cin,inserted_text);
	}
	
	void display()
	{
	    cout<<"Text is: "<< inserted_text;
	}
	
	
	int count_ch()
	{
		static int counter = 0;
		
        static int i = 0;
          if(inserted_text[i] != '\0')
          {
          	if(inserted_text[i] == ' ' || inserted_text[i] == ',' || inserted_text[i] == '.' || inserted_text[i] == ';')
			  {
			  	
			  }
			else
			{
			  counter++;
		    }
		    
	        i++;
		  }
		  else
		  {
		  		return counter;
		  }

		count_ch();
	
	}
	
	int count_words()
	{
		static int counter = 0;
		
        static int i = 0;
          if(inserted_text[i] != '\0')
          {
          	if(inserted_text[i] == ',' || inserted_text[i] == '.' || inserted_text[i] == ';')
			{
			  	
			}
			else if(inserted_text[i] == ' ' )
			{
				counter++;
			}
			  
	        i++;
		  }
		  
		  else
		  {
		  		return counter + 1;
		  }

		count_words();
	}
	
	int redunant_count()
	{
        static int count = 0;
        string temp_check_string = " ";
        
        static int i = 0;
        while (inserted_text[i] != '\0')
		{
            if(inserted_text[i] == ' ')
			{
                int j = i + 1;
                string checkwith = " ";
                
                while (inserted_text[j] != '\0')
			    {
                    if(inserted_text[j] == ' ')
                    {
                        if(checkwith == temp_check_string)
						{
                            count++;
                        }
                        
                        checkwith = " ";
                        
                    }
                    
                    else
					{
                    checkwith += inserted_text[j];
                    } 
                    
                    j++;
                }
                
                if (inserted_text[j] == '\0')
				{
                    if(checkwith == temp_check_string)
					{
                        count++;
                    }
                }
                temp_check_string = " ";
            }
            else
			{
                temp_check_string += inserted_text[i];
            }
            
            i++;
        }

        return count;
    }
	
};

int main()
{
	Text_Editor x;
	
    x.insert_text();
    x.display();
	
	cout << endl;
	
	cout << "Total characters: " << x.count_ch() << endl;

	cout << "Total words: " << x.count_words() << endl;

    cout << "Total redunant words: " << x.redunant_count() << endl;
	
	return 0;
	
}
