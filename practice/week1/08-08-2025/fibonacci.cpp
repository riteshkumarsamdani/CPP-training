#include <iostream>
using namespace std;
int fibonacci(int x) {
   if (x==0 || x==1) {
       return x; 
   }else{
       return fibonacci(x-1)+fibonacci(x-2); 
   }
}

int main() {
   int terms = 10; 
   cout << "Fibonacci Series: ";
   for (int i = 0; i < terms; i++) {
       cout << fibonacci(i) << " ";
   }

   return 0;
}