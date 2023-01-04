#include <iostream>
using namespace std;

class polynomial 
{
    float A,B;  /* private */

public:

    polynomial(){A=B=1;}
    polynomial(float a,float b){A=a; B=b;}

    void display()
    {
        if(A>=0)
            cout << "y=" << B <<"X+"<< A ;
        if(A<0)
            cout << "y=" << B <<"X"<< A ;

        cout << endl;
        
        
        
        
   
        
        
        
        
    }
//-----------------------------------------------------------
    polynomial operator + (polynomial a)
    {
        polynomial b;

        b.A= A + a.A;
        b.B= B + a.B;

        return b;
    }
//-----------------------------------------------------------
    polynomial operator - (polynomial a)
    {
        polynomial b;

        b.A= A - a.A;
        b.B= B - a.B;

        return b;
    }
//-----------------------------------------------------------
    polynomial operator = (polynomial a)
    {
        A= a.A;
        B= a.B;
    }
};

/////////////////////////////////////////////////////
class polynomial2D : public polynomial
{
         float C;
    public:
        float A,B;

        polynomial2D(){C=B=A=1;}
        polynomial2D(float c,float b, float a){C=a; B=b; A=a;}

        void display()
        {
            if(B>=0 && A>=0)
            cout << "y=" << C <<"X^2+"<< B << "X+"<<A;

            if(B<0 && A>=0)
            cout << "y=" << C <<"X^2"<< B << "X+"<<A;

            if(B<0 && A<0)
            cout << "y=" << C <<"X^2"<< B << "X"<<A;

            if(B>=0 && A<0)
            cout << "y=" << C <<"X^2+"<< B << "X"<<A;

            cout<< endl;
        }
};
/////////////////////////////////////////////////
int main()
{
    polynomial A(4,4),B(6,8),C;


    C=A+(B);
    C.display();

    A=(B);
    C.display();

    C=A-(B);
    C.display();

//*************************************

    polynomial2D D(1,-4,4),E(1,4,4),F;

    return 0;
}