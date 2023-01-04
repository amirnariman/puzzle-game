#include <iostream>
using namespace std;
cout<<"salam"<<endl;

int main(){
    
    cout<< "matris1: satr? & sotoon? " ;
    int m;
    int n;
    cin>>m>>n ;
    
    cout<< "matris2: satr? & sotoon? " ;
    int p;
    int q;
    cin>>p>>q;
    
    if(n != p){
        cout<<"INVALID"<<endl;
    }
    
    // Init values in m1.
    int m1[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>m1[i][j];
        }
    }
    // Init values in m2.
    int m2[p][q];
    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++){
            cin>>m2[i][j];
        }
    }
    
    // create our resultant matrix m3 with shape m,q
    int m3[m][q];
     for(int i = 0; i < m; i++){
        for(int j = 0; j < q; j++){
            m3[i][j] = 0;
        }
    }
    //  Finding the product of 2 matrices and storing it in a new matrix.
    for(int i = 0; i < m; i++){
        for(int j = 0; j < q; j++){
            for(int k = 0; k < n;k++){
                m3[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    
    // Printing the resultant matrix.
    for(int i = 0; i<m;i++){
        for(int j = 0; j <q; j++){
            cout<<m3[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
