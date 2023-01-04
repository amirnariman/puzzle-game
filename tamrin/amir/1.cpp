#include "iostream"
using namespace std;

class Student{

public:
  string name;
  int age;
  double number;

  public:
   void Natige(){
    cout<<"your name:"<<name<<endl<<"your age:"<<age<<endl<<"your number:"<<number;}
     
};

 main(){
   
   Student aval;
   Student dovom;

  aval.name="amir";
  aval.age=19;
  aval.number=912 ;
  aval.Natige();

cout<< endl;

dovom.name="ali";
dovom.age= 10;
dovom.number= 957;
dovom.Natige();
    
}