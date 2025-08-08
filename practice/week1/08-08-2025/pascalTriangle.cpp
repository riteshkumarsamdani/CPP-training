#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"enter no of rows for pascal triangle"<<endl;
    cin>>rows;
    cout<<"printing pascal traingle"<<endl;
    for(int i=0;i<rows;i++){
        int space=rows-i;
        for(int j=0;j<space;j++){
            cout<<" ";
        }
        int temp;
        for(int j=0;j<=i;j++){
            if(j==0){
                temp=1;
            }
            else{
                temp=temp*(i-j+1)/j;
            }
            cout<<temp<<" ";
        }
        cout<<endl;
    }
    return 0;
}