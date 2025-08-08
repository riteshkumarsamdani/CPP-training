#include<iostream>
using namespace std;
int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
long multiply(int a,int b){
    return a*b;
}
double division(int a,int b){
    return (double)a/b;
}
int main(){
    cout<<"enter ther operation to perform(+.-,*,/)"<<endl;
    char op;
    cin>>op;
    int a,b;
    cout<<"enter 2 value"<<endl;
    cin>>a>>b;
    switch(op){
        case '+':
            cout<<add(a,b)<<endl;
            break;
        case '-':
            cout<<sub(a,b)<<endl;
            break;
        case '*':
            cout<<multiply(a,b)<<endl;
            break;
        case '/':
            if(b==0){
                cout<<"invalid b"<<endl;
                break;
            }
            cout<<division(a,b)<<endl;
            break;
        default:
            cout<<"enter valid value"<<endl;
    }
    return 0;
}