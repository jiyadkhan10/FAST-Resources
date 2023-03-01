#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
   Aim: Reading and Writing a Binary file 
 
   Purpose: to create a new image from an existing image file
  
 */

int main () {
 
  char ch;
    
    ifstream iObj("/demo-data/moon.jpg", ios::in|ios::binary);
    
    ofstream oObj("/demo-data/moon1.jpg", ios::out|ios::app|ios::binary);
      
    cout<<"Creating copy of image file. \n";    
    
    int cntr = 0;
    
     while(!iObj.eof()) //read till end-of-file:
     {
         cntr++;  
         ch = iObj.get();
         //cout<<ch;
         oObj.put(ch); 
     }
         
    iObj.close();
    oObj.close();
  
    
    cout<<"\n \n \n \n Copy created Successfully. " << cntr; 
 
return 0;
}