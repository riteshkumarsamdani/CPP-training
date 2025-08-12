#include<iostream>
using namespace std;
int main(){
    int row,col;
    cout<<"enter number of row in matrix: ";
    cin>>row;
    cout<<"enter number of column in matrix: ";
    cin>>col;
    int arr[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"enter number :";
            cin>>arr[i][j];
        }
    }
    cout<<"printing matrix element:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}