#include<iostream>
#include "user.h"
using namespace std;
int main(){
    int age;
    string name;
    cout<<"enter your name"<<endl;
    cin>>name;
    greet(name);
    cout<<"enter your age"<<endl;
    cin>>age;
    verifyAge(age);
    return 0;
}
