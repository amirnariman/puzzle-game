#include "iostream"
using namespace std;

class Polynomial{

    public:
    Polynomial(){
        A=1;
        B=1;
    }
    Polynomial(int a,int b):A(a),B(b){};
    Polynomial operator - (Polynomial );
    Polynomial operator + (Polynomial );
    Polynomial operator = (Polynomial );
    void print ();    
    void disply();
    

    private:
    int A,B;

};
Polynomial Polynomial :: operator + (Polynomial a){
     Polynomial b;

        b.A= A + a.A;
        b.B= B + a.B;

        return b;
}
Polynomial  Polynomial ::operator - (Polynomial a){
     Polynomial b;

        b.A= A - a.A;
        b.B= B - a.B;

        return b;

}
Polynomial  Polynomial::operator = (Polynomial a){

    A=a.A;
    B=a.B;


}


void Polynomial::print(){
    cout<<"("<<A<<","<<B<<")"<<endl;

}
void Polynomial::disply(){
    cout<<"y="<<A<<"x"<<((B<0)?"":"+")<<B<<endl;
}

int main(){
    Polynomial  t(-5,-3);
    Polynomial c(1,5);
    Polynomial x;
    Polynomial m;
    Polynomial e;
    c=t;
    t.disply();
    c.disply();
    cout<<"------------------"<<endl;
    
    

}