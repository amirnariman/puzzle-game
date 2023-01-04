#include <iostream>
using namespace std;

class number
{
    int a;
    int b;
public:
    number()
    {
        a=0;
        b=0;
    }
    number(int x, int y)
    {
        a=x;
        b=y;
    }

    void Display()
    {
        if( b>=0)
            cout<<a<< "+" << b <<"i"<<endl;
        else if( b<0)
            cout<<a<< b <<"i" << endl;
    }

    number operator + (number x)
    {
        number temp;

        temp.a = a + x.a;
        temp.b = b + x.b;

        return temp;
    }

    number operator - (number x)
    {
        number temp;

        temp.a = a - x.a;
        temp.b = b - x.b;

        return temp;
    }
    void operator += (number x)
    {
        a += x.a;
        b += x.b;
    }
    void operator ++ ()
    {
        ++a;
        ++b;
    }
    void operator -- (int)
    {
        a--;
        b--;
    }


};
int main ()
{
    number x1(2,3), x2(4,3), temp;

    x1.Display();
    x2.Display();

    temp = x1+x2;
    temp.Display();

    temp = x1+x2;
    temp.Display();

    temp = x1-x2;
    temp.Display();

    x1+=x2;
    x1.Display();

    ++x2;
    x2.Display();

    x2--;
    x2.Display();

        return 0;
}