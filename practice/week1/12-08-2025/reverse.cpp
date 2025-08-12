#include<iostream>
using namespace std;
int main(){
    string str;
    cout<<"enter string to reverse: ";
    cin>>str;
    cout<<"entered string is : "<<str<<endl;
    char temp;
    int length=str.length();
    for(int i=0;i<length/2;i++){
        temp=str[i];
        str[i]=str[length-i-1];
        str[length-i-1]=temp;
    }
    cout<<"reverse string is: "<<str<<endl;
    return 0;
}