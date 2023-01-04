#include "iostream"
using namespace std;
int main(){
    int Score[5];
    double  sum=0;


    cout<<"enter number of array :"<<endl;
    for (int i=0;i<5;i++){
      cin>>Score[i];
    }

    for (int j=0;j<5;j++){
        sum+=Score[j];

    }
    cout<<"avarage:"<<sum/5;
    





}