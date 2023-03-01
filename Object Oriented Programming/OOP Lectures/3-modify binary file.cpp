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
      
    cout<<"Creating a modified image  \n";    
    
    int cntr = 0;
    
     while(!iObj.eof()) //read till end-of-file:
     {
       cntr++;  
       if(cntr >= 0 && cntr <=800 )
       { 
         ch = iObj.get();
         //cout<<ch;
         oObj.put(ch); 
       }
       else if(cntr > 800 && cntr < 1200 )
       { 
          ch = iObj.get(); 
       }
       else if(cntr >= 1200)
       {
           ch = iObj.get();
           //cout<<ch;
           oObj.put(ch); 
       }

     }
         
    iObj.close();
    oObj.close();
  
    
    cout<<"\n \n \n \n Image Created and Modified Successfully. " << cntr; 
 
return 0;
}