#include<iostream>
#include<bits/stdc++.h>

int calc(int arr[]){
    return sizeof(arr);
}
int main(){
    int arr[]={1,2,3,4,5};
    std::cout<<sizeof(arr);
    std::cout<<calc(arr);
    return 0;
}