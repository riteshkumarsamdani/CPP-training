#include<iostream>
#include "user.h"
using namespace std;
void verifyAge(int age){
    if(age>=18){
        cout<<"authentication complete..."<<endl;
        cout<<"you can procced"<<endl;
    }
    else{
        cout<<"you are not authorise to move further..."<<endl;
        cout<<"plase go back"<<endl;
    }
    return;
}
void greet(string name){
    cout<<"welcome to our site "<<name<<endl;
    return;
}
