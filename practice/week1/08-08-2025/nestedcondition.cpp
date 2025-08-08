#include<iostream>
using namespace std;
int main(){
    int age=10;
    if(age<=15){
        cout<<"child"<<endl;
    }
    else if(age<=50){
        cout<<"adult"<<endl;
    }
    else{
        cout<<"aged"<<endl;
    }
    return 0;
}