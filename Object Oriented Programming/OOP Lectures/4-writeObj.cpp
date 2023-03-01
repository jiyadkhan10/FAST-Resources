#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class person
{
private:
    char name[30];
    int age;
    
public:
    void getData()
    {
        cout<<"Enter name: ";
        cin >> name;
        
        cout<<"Enter age: ";
        cin >> age;
    }
    void showData()
    {
        cout<<"Name = " << name << " age = " << age ;
    }
};

int main () 
{
  
  person p;
  
  p.getData();
  p.showData();
   
  ofstream outfile("/demo-data/myObj1.DAT", ios::binary);
  
  outfile.write(reinterpret_cast<char*>(&p),sizeof(p));
  
  outfile.close();
  
  return 0;
}
