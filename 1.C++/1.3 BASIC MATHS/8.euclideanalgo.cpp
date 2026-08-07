#include<bits/stdc++.h>
using namespace std;

int main(){

//gcd(a,b) = gcd(a-b, b)
//algo would be gcd(a,b) = gcd(a%b, b) where a>b 
//keep repeating it until atleast one of the term becomes 0
//when such happens the other becomes zero
int a,b,gcd;
while (a>0 && b>0){

    if (a>b) {
        a = a%b;
    }
    else {
        b = b%a;
    }
}
    if (a == 0 ) {
        cout<< "gcd is: " << b;
    }
    else {
        cout<< "gcd is: " << a;
    }



}