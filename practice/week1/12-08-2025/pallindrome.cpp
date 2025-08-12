#include<iostream>
using namespace std;
bool checkPallindrome(string str){
    for(int i=0;i<str.length()/2;i++){
        if(str[i]!=str[str.length()-1-i]) return 0;
    }
    return 1;
}
int main(){
    string str;
    cout<<"enter string to check pallindrome:";
    cin>>str;
    bool isPallindrome=checkPallindrome(str);
    if(isPallindrome==1){
        cout<<"entered string is pallindrome"<<endl;
    }
    else
        cout<<"entered string is not pallindrome"<<endl;
    return 0;
}