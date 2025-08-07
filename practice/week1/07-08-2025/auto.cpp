#include <bits/stdc++.h>
using namespace std;
int main()
{
    auto an_int=26;
    auto a_bool=false;
    auto a_float=26.24;
    auto ptr=&a_float;

    cout<<"id for bool"<<typeid(a_bool).name()<<endl;
    cout<<"id for int"<<typeid(an_int).name()<<endl;
    cout<<"id for float"<<typeid(a_float).name()<<endl;
    cout<<"id for pointer"<<typeid(ptr).name()<<endl;
    return 0;
}