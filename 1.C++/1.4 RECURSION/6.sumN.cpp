#include<bits/stdc++.h>
using namespace std;
//my approach
void recsum(int i, int n, int summ){
    if (i > n) {
        cout << summ;
        return;
    }

    summ = i + summ; 
    recsum(i+1,n,summ);
}

//strivers approach

//1 parameterised
int suma(int i, int sum){
    if (i<1) {
        cout<< sum
        return 0;
    }

    return suma(i-1, sum+i);
}

//2 funtional way
int sumb (int n){
    if (n == 0) return 0;
    return n + sumb(n-1); 
}

int main(){
int n,i,summ;
cout << "enter the value of N: " << endl;
cin>> n;
i = 1;
summ = 0;
recsum(i,n,summ);
}

/* i made two mistakes initially first dont pass i++ in functions
use i+1 because i++ passes current value first before incrementing 
that causes the value of i to stay 1 in the function before it
increments hence leading to stack overflow
*/