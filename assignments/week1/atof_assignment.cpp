#include<iostream>
using namespace std;
double atof(string str){
    double ans=0.0;
    int sign=1;
    int i=0;
    bool decimal=false;
    double temp=1;
    while(str[i]==' '){
        i++;
    }
    if(str[i]=='-'){
        sign=-1;
        i++;
    }
    else if(str[i]=='+'){
        i++;
    }
    while(i<str.length()){
        
        if(!decimal && str[i]<='9' && str[i]>='0'){
            ans=ans*10+(str[i]-'0');
        }
        else if(decimal && str[i]<='9' && str[i]>='0'){
            ans=ans*10+(str[i]-'0');
            temp=temp*10;
        }
        else if(str[i]=='.') decimal=true;
        else break;
        i++;
    }
    ans=ans*sign;
    return ans/temp;
}
int main(){
    string str;
    cout<<"enter string for conversion"<<endl;
    cin>>str;
    double ans=atof(str);
    cout<<"string value is:"<<str<<"\natof value is:"<<ans<<endl;
    return 0;
}