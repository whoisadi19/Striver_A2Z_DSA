#include<bits/stdc++.h>
using namespace std;

int fibb(int n){
if (n<=0){
    return 0;
}
if (n ==1){
    return 0;
    }
else if (n ==2 ){
    return 1;
}
return fibb(n-2) + fibb(n-1);
}




int main(){
    int n;
    cout<< "enter number of digits of fibonacci" <<endl;
    cin>> n;
    //nth fibonacci digit
   cout<<"your nth fibonacci digit is :"<< fibb(n) <<endl;
   //for printing entire series upto n
   cout<<"your fibonacci series is: " <<endl;
   for (int i = 1; i <=n;i++){
    cout << fibb(i)<<endl;
   }
}