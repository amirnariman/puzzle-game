#include <iostream>
using namespace std;
//----------------------------------
class stack
{
    int size, top, *A;

public:
    stack (int sizestack)
    {
        size=sizestack;
        top=-1;
        A=new  int [size];
    }
    ~stack(){delete [] A;}

    stack(stack &st)
    {
        size=st.size;
        top=st.size;
        A=new int [size];

        for (int i=0; i<=st.top; i++)
            A[i]=st.A[i];

    }

    void push (int &item){A[++top]=item;}
    void pop (int &item){item =A[top--];}
    void display()
    {
        cout<<"Element of stack: ";
            for (int i=top; i>=0; i--)
                cout<< A[i] << " ";
            cout<< endl;
    }
};

//----------------------------------

int main()
{
    stack s1(10);
    for(int i=0; i<10; i++)
    {
        s1.push(i);
    }
    s1.display();

    int x;
    s1.pop(x);
    cout<<"Delete 1 element of s1: "<< x <<endl;

    s1.display();

    return 0;
}