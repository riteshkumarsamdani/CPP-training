#include<iostream>
using namespace std;
void towerOfHanoi(string start,string end,string hollow,int n){
    if(n==0){
        return;
    }
    towerOfHanoi(start,hollow,end,n-1);
    cout<<"move disc "<<n<<" from rod "<<start<<" to rod "<<end<<endl;
    towerOfHanoi(hollow,end,start,n-1);
}
int main(){
    cout<<"enter number of plates in TOH"<<endl;
    int n;
    cin>>n;
    towerOfHanoi("start","end","hollow",n);
    return 0;
}