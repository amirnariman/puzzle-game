#include <iostream>
#include <string>

using namespace std;

class person
{
 
    public:
    int age ;
    string number;
    string name;

        public: void display ()
{
            cout<< " enter your age: "<< age<< endl;
            cout<< "enter your number :" << number<< endl;
            cout<< "enter name :" << name << endl;
         
}
};

 int main (){

        person adam1;
        person adam2;

        adam1.age = 19;
        adam1.number= "9162241512";
        adam1.name = " amir ";
        adam1.display ();

        cout << endl;

        adam2.age = 40;
        adam2.number = "9131014077";
        adam2.name = " hasan";
        adam2.display ();

}