#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number to print pattern:";
    cin>>n;
    int m=2*n-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        for(int j=0;j<m-(2*(i+1));j++){
            cout<<"  ";
        }
        if(n%2==0 && i<n-1) cout<<"  ";
        if(n%2==0 && i==n-1) cout<<"1 ";
        for(int j=0;j<=i;j++){
            if(i==n-1 && j==0){
                continue;
            }
            else if(j%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(j%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        for(int j=0;j<m-(2*(i+1));j++){
            cout<<"  ";
        }
        if(n%2==0 && i<n-1) cout<<"  ";
        for(int j=0;j<=i;j++){
            if(i==n-1 && j==0){
                continue;
            }
            else if(j%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
