#include <bits/stdc++.h>
using namespace std;

int main(){

//aim is to print prime numbers

// a prime number is a number that has exactly 2 factors, 1 and the number itself

//general approach
//tc = O(n)
int count, i, n;

count = 0;
cin<< n;
for (i = 0; i<=n; i++ ){
    if (n%i == 0 ){
        count = count + 1;
    }
}
if (count == 2){
    cout<< "input is a prime number";

} 
else {
    cout << "not prime";
}


//better approach 

for (i = 1; i*i < = n; i++){
    if (n%i ==0){
        count ++;
    
    if (n/i != i ){
        count++ ;
    }
}
}
if (count == 2){
    cout << "num is a prime"
}

    return 0;
}