#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
   Aim: Reading a Binary file like image, MS Word etc
 
   Purpose: read an image file
  
 */

int main () {
 
  char ch;
  string line;
    
    //ifstream iObj("/demo-data/moon.jpg", ios::in|ios::binary);
    ifstream iObj("/demo-data/myWord.docx", ios::in|ios::binary);
    
      
    cout<<"Reading Binary File \n";    
    
    int cntr = 0;
    
     while(!iObj.eof()) //read till end-of-file becomes true
     {
         cntr++;  
         ch = iObj.get();
         //getline(iObj,line);
         //iObj.read(&ch, sizeof(ch));
         cout<<ch;
         //cout<<line;
     }
         
    iObj.close();
    
    cout<<"\n \n \n \n Total characters: " << cntr; 
 
return 0;
}