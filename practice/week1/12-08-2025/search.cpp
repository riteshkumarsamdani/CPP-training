#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter number in array:";
        cin>>arr[i];
    }
    cout<<"enter number to search:";
    int num;
    cin>>num;
    for(int i=0;i<n;i++){
        if(num==arr[i]){
            cout<<"number found at index "<<i<<endl;
        }
        else if(i==n-1){
            cout<<"number is not ptresent"<<endl;
        }
    }
    return 0;
}