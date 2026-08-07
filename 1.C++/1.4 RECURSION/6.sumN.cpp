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