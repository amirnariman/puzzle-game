#include <iostream>
using namespace std;
/////////////////////////////////////////////////////
void line()
{
    for(int i=0; i<25; i++)
        cout<<"-";
}
/////////////////////////////////////////////////////
class polynomial
{
    float A,B;

public:

    polynomial(){A=B=1;}
    polynomial(float a,float b){A=a; B=b;}

    void display()
    {
        if(B>=0 && A>=0 )
            cout << B <<"X+"<< A ;
        if(B>=0 && A<0 )
            cout << B <<"X"<< A ;

        if(B<0 && A>=0)
            cout << B <<"X+"<< A ;
        if(B>=0 && A<0)
            cout << B <<"X"<< A ;

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

        polynomial2D(){C=1;}
        polynomial2D(float c,float b, float a): polynomial(c,b) {C=a;}

        void display()
        {
            cout<< C <<"X^2" ;
            polynomial::display();
        }
};
/////////////////////////////////////////////////////
int main()
{
    polynomial A(4,4),B(4,4),C;


    C=A+(B);
    cout << "y= " ;
    C.display();

    A=(B);
    cout << "y= " ;
    C.display();

    C=A-(B);
    cout << "y= " ;
    C.display();

//*********************************************

    polynomial2D D(1,-4,4),E(1,4,4),F;
    cout << "y= " ;
    D.display();

    return 0;
}