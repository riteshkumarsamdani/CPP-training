#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool checkInf(string s1){
    string data[]={"inf","inF","iNf","iNF","Inf","InF","INf","INF"};
    for(int i=0;i<8;i++){
        if(s1==data[i]) return 1;
    }
    return 0;

}
bool checkNan(string s1){
    string data[]={"nan","naN","nAn","nAN","Nan","NaN","NAn","NAN"};
    for(int i=0;i<8;i++){
        if(s1==data[i]) return 1;
    }
    return 0;
}
double atof(string str){
    double ans=0.0;
    int sign=1;
    int i=0;
    bool decimal=false;
    double temp=1;
    bool exponent=false;
    bool power=false;
    int r=0;
    int rs=1;
    bool hexa=false;
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
        if(power || exponent){
            if(str[i]<='9' && str[i]>='0'){
                r=r*10+str[i]-'0';
            }
            else if(str[i]=='-' && r==0) rs=-1;
            else if(str[i]=='+' && r==0) rs=1;
            else break;
        }
        else if(hexa){
            if(str[i]<='9' && str[i]>='0'){
                ans=ans*16+str[i]-'0';
            }
            else if(str[i]<='f' && str[i]>='a'){
                ans=ans*16+(str[i]-'a'+10);
            }
            else if(str[i]<='F' && str[i]>='A'){
                ans=ans*16+(str[i]-'A'+10);
            }
            else if(str[i]=='p' || str[i]=='P'){
            if(power==false){
                power=true;
            }
            else break;
        }
            else break;
        }
        else if(!decimal && str[i]<='9' && str[i]>='0'){
            ans=ans*10+(str[i]-'0');
        }
        else if(decimal && str[i]<='9' && str[i]>='0'){
            ans=ans*10+(str[i]-'0');
            temp=temp*10;
        }
        else if(str[i]=='.') decimal=true;
        else if(str[i]=='e' || str[i]=='E'){
            if(exponent==false && hexa==false){
                exponent=true;
            }
            else break;
        }
        else if(str[i]=='x' || str[i]=='X'){
            if(!hexa && ans==0){
                hexa=true;
            }
            else break;
        }
        else if(checkInf(str.substr(i,3))){
            return sign*INFINITY;
        }
        else if(checkNan(str.substr(i,3))){
            return sign*NAN;
        }
        else break;
        i++;
    }
    ans=ans*sign;
    ans=ans/temp;
    if(exponent){
        if(rs==-1){
            while(r){
                ans/=10;
                r--;
            }
        }
        else{
            while(r){
                ans=ans*10;
                r--;
        }
        }
        
    }
    if(power){
        if(rs==-1){
            while(r){
                ans/=2;
                r--;
            }
        }
        else{
            while(r){
                ans=ans*2;
                r--;
        }
        }
        
    }
    return ans;
}
int main(){
    string str;
    cout<<"enter string for conversion"<<endl;
    cin>>str;
    double ans=atof(str);
    cout<<"string value is:"<<str<<"\natof value is:"<<ans<<endl;
    return 0;
}
