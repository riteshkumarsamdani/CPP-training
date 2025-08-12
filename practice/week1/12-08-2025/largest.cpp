#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter total number of element: "<<endl;
    cin>>n;
    int largest=-1;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter number "<<i+1<<" : ";
        cin>>arr[i];
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    cout<<"array :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"largest number among array is: "<<largest<<endl;
    return 0;
}