#include<iostream>
using namespace std;
int main(){
    int col,row;
    cout<<"enter number of row:";
    cin>>row;
    cout<<"enetr number of col:";
    cin>>col;
    int A[row][col];
    int B[row][col];
    cout<<"enter number in A matrix:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"enter number:";
            cin>>A[i][j];
        }
    }
    cout<<"enter number in B matrix:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"enter number:";
            cin>>B[i][j];
        }
    }
    cout<<"calculating sum of two matrix:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<A[i][j]+B[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}