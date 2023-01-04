#include <iostream>
using namespace std;

class ATM 
{
private:
    int M ;
    int b;
public:
    static int T;
    ATM(int m){M=m; T++;}

    void operator - ( )
    {    
        cin>>b;
        M-=b ;
        T++ ;
    }

    void operator ++ ( )
    {    
        M+=1000 ;
        T++ ;
    }

    void operator --(int)
        { M-=2000; T++; }

        void display(){
            cout<<"mojoodi:"<<M  ;
            cout<<"\n tarakonesh:"<<T <<endl;
        }     
};
    int ATM ::T=0 ;


int main()
{
    ATM A(10000);
    ++A;
    A.display();
    -A;
    A.display();
    A--;

    return 0;
}