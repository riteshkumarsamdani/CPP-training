#include<iostream>
using namespace std;
long long fact(int n){
    if(n<=1) return 1;
    return n*fact(n-1);
}
int main(){
    int n;
    cout<<"enter number to find factorial"<<endl;
    cin>> n;
    cout<<"factorial of number:"<<n<<" is"<<fact(n)<<endl;
    return 0;
}