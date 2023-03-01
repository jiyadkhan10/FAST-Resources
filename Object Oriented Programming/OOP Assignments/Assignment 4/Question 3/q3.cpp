//Name: Jiyad Khan
//Roll No: 19I-1771
//Section: CS-D
//Assignment 4
//Q3

#include <iostream>
using namespace std;
class Book
{
	private:
		
		int rupees;
        int paise;
		
    public:
    	
        Book() //default constructor
		{
			rupees = 0;
			paise = 0;
		}
        
        Book(int rp , int pa) //parameterize constructor
		{
            rupees = rp;
            paise = pa;
        }
        
        Book operator+(Book& book) //operator overloading
		{
            Book new_book;
            new_book.rupees = this->rupees + book.rupees;
            new_book.paise = this->paise + book.paise;
            new_book.rupees += (new_book.paise / 100);
            new_book.paise = new_book.paise % 100;
            return new_book;
        }
    
        void print_price() // to print the price
		{
            cout << rupees << " rupees and " << paise << " paise" << endl;
        }
};

int get_price() // to get the price
{
    int p;
    cin >> p;
    while(p < 0) //invlaid price
	{
        cout << "Invalid price , please enter price > 0" << endl;
        cout << "Enter price again : ";
        cin >> p;
    }
    return p;
}
int main()
{
	//variable declaration
    int r1;
	int p1;
    int r2;
	int p2;
	
	cout << "Enter price for first Book: " << endl; // price of first book
    
    cout << "Rupees : ";
    r1 = get_price();
    
    cout << endl;
    
    cout << "Paise : ";
    p1 = get_price();
    
    Book b1(r1,p1);
    
    cout << "Enter price for second Book: " << endl; // price of second book
    
    cout << "Rupees : ";
    r2 = get_price();
    
    cout << endl;
    
    cout << "Paise : ";
    p2 = get_price();
    
    Book b2(r2,p2);
    
    Book b3 = b1 + b2;
    
    cout << "Total price is : "; //total price
    b3.print_price();
    
    return 0;
}
