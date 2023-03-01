//Name: Jiyad Khan
//Roll Number: 19I-1771
//Assignment 3
//Q10

#include<iostream>
#include<cstring>

using namespace std;

class Array
{
    private:    // think about the priate data members
    	int *array;
    	int size;

    public:
    	Array() //default constructor
	    {
     		array = NULL;
    		size = 0;
    	}

	    Array(int s) //parametized constructor
    	{
	    	size = s;
	    	array = new int[size];
	    	
	    	int i = 0;
		    while (i < size)
	    	{
		    	cout << "Enter " << i + 1 << " value: ";
		    	cin >> array[i];
		    	
		    	i++;
		    }
	    }

	    Array(int* arr, int s) //initializes the array with an existing array
	    {
    		size = s;
    		
    		int i = 0;
	    	while (i < size)
	    	{
		    	array[i] = arr[i];
		    	i++;
		    }
	    }
	    
	    Array(const Array &arr) //copy constructor
	    {
	    	array = arr.array;
		}

    	int getAt(int i) //returns the integre at index[i]
    	{
    		if (i > size)
	    	{
		     	cout << "Error!!!!!!" << endl;
		    	return 0;
		    }
		    else
		    {
			    return array[i];
		    }
    }

    void setAt(int i, int val) //returns the value at index[i]
  	{
		if (i > size)
		{
			cout << "Error!!!!" << endl;
			return;
		}
		else
		{
			 array[i-1] = val;
		}
	}
	
	Array subArr(int pos, int siz) // returns a sub_array of size siz starting from pos
	{
		Array sub_array;
		sub_array.array = new int[siz];
		
		int j = 0;
		for(int i = pos; i < siz; i++)
		{
			sub_array.array[j] = array[i];
			j++;
		}
		
		return sub_array;
	}
	
	Array subArr(int pos) // returns a sub-array from the given position to the end
	{
		Array sub_array;
		sub_array.array = new int[size];
		
		int j = 0;
		for(int i = pos; i < size; i++)
		{
			sub_array.array[j] = array[i];
			j++;
		}
		
		return sub_array;
	}
	
	int *subArrayPointer(int pos, int siz) // returns a sub_array of size siz starting from pos
	{		
		int *sub_array_pointer;
		sub_array_pointer = new int[siz];
		
		int j = 0;
		for(int i = 0; i < siz; i++)
		{
			sub_array_pointer[j] = array[i];
			j++;
		}
		
		return sub_array_pointer;
	}
	
	int *subArrayPointer(int siz) // returns a sub-array from the given position to the end
	{		
		int *sub_array_pointer;
		sub_array_pointer = new int[size];
		
		int j = 0;
		for(int i = 0; i < size; i++)
		{
			sub_array_pointer[j] = array[i];
			j++;
		}
		
		return sub_array_pointer;
	}

	void push_back(int a) //adds an element to the end of the array
	{
		array[size] = a;
		size++;
	}

	int pop_back() //remove and returns the last element of the array
	{
		int x;
		x = size;
		size--;
		return array[x - 1];
	}

	int insert(int idx, int val) // insert the value val at idx
	{
		if (idx >= 0 && idx < size)
		{
			array[idx - 1] = val;
			return 1;
		}
		else
		{
			return -1;			
		}
	}
	int erase(int idx, int val) // erase the value val at idx
	{
		if (idx > size)
		{
			cout << "Error!!!!!" << endl;
			return 0;
		}
		else
		{
			int i = idx;
			while(i < size)
			{ 
				array[i] = array[i + 1];
				i++;	
			}
			size--;	
		}
	}

	int length() //returns the size of the array
	{
		return size;
	}
	
	void clear() // clear the content of the array
	{
		int i = 0;
		while(i < size)
		{
			  array[i] = 0;
			  i++;
		}
	}
	
	int value(int idx) // return the value at idx
	{
		if (idx > size)
		{
			cout << "Error!!!!!" << endl;
		}
		else
		{
			return array[idx - 1];
		}
	}
	
	void assign(int idx, int val) // assigns the value val to the element at index idx
	 {
		if (idx > size)
		{
			cout << "Error!!!!!!" << endl;
			return;
		}
		else
		{
			array[idx - 1] = val;
		}
	}
	
	void copy(const Array &arr) //copy the passed array
	{
        array = arr.array;	   
	}
	
	void copy(const int *arr, int s) // copy the passed array
	{
		int *x = new int[s];
		int i = 0;
		
		while(i < s)
		{
			x[i] = array[i];
		}
	}
	
	void display() //display the array
	{
		cout << endl;
		cout << "*****Array*****" << endl;
		
		int i = 0;
		while(i < size)
		{
			cout << array[i] << " ";
			i++;
		}
		cout << endl;
	}
	
	bool isempty() //return true if the array is empty
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	Array find(int val) // return an array containing all the indexes of integre being searched
	{
		Array find_array;
		find_array.array = new int[size];
		
		int j = 0;
		for(int i = val; i < size; i++)
		{
			find_array.array[j] = array[i];
			j++;
		}
		
		return find_array;
	}
	
	bool equal(Array &check_array) // should retue true if both Arrays are same
	{
	    int i = 0;
	    while(i < size)
	    {
	    	if(array[i] == check_array.array[i])
	    	{
	    		return true;
			}
			
			else
			{
				return false;
			}
			
			i++;
		}
		
	}

	int sort() //Sort an array
	{
		int x = 0;
		
		for(int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (array[i] < array[j])
				{
				     x = array[i];
				     array[i] = array[j];
				     array[j] = x;
				}	
			}
		}
	}

	void reverse() //Reverse the content of the array 
	{
		int x = 0;
        int y = size - 1;
        int z = 0;
        
        while(x < y)
		{
            
            z = array[x];
            array[x] = array[y];
            array[y] = z;
            
            x++;
            y--;
        }
		
	}
	
	~Array() //destructor
	{
		delete[]array;
	}
};

int main()
{
	//Creation of an object

	int s;
	int index;
	int val;
	int search;
	
    cout << "Enter the size: " << endl;
    cin >> s;

    Array first_array(s);
    
    cout << "Array for object 1 : ";
    first_array.display();  
    
    cout << endl;
    
    cout << "Get the value at which index? " << endl;
    cin >> index;
    
    cout << "Value at index " << index << ": " << first_array.getAt(index) << endl;
    
    cout << endl;
    
    cout << "Set new value to index: " ;
    cin >> index;
    
    cout << "Enter new value: ";
    cin >> val;
    
    first_array.setAt(index,val);
    first_array.display();
    
    cout << endl;
    
    cout << "Successfully Updated...." << endl;
    
    cout << endl;
    
    cout << "Array is empty? : " << first_array.isempty() << endl;
    
    cout << endl;
    
    cout << "Pop last element from array : " << endl;
    first_array.pop_back();
    
    cout << "Pushing 10 at the end..." << endl;
    first_array.push_back(10);
      
    cout << "Array for object 1 : " << endl;
    first_array.display();
    
    cout << endl;
    
    cout << "Inserting 6 at index 6(1 for success, -1 for fail) : " << first_array.insert(6,6) << endl;
    
    int len = first_array.length();
    
    cout << "Array after updation : ";
    first_array.display();
    
    cout << endl;
    
    cout << "Length of array is : " << len << endl;
    
    cout << endl;
    
    cout << "Enter the values in second array: " << endl;
    Array second_array(s);
    
    cout << "Array for object 2 : ";
    second_array.display(); 
    
    cout << "Reverse the array......" << endl;
    cout << "Array after reversing: ";
	second_array.reverse();
    second_array.display();
    
    cout << endl;
    
    cout << "Search for element: ";
    cin >> search;
    
    second_array.find(search);
    
    cout << endl;
    
    cout << "New array: ";
    second_array.display();
    
    cout << endl;
    
    cout << "Sorting the new array......" << endl;
    cout << "Array after sorting: ";
    second_array.sort();
    second_array.display();
    
    cout << endl;
    
    return 0;
    
}
