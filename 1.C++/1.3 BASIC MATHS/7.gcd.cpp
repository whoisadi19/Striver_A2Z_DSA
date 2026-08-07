#include<bits/stdc++.h>
using namespace std;

int main(){
//aim is to find GCD 
//greatest common divisor or highest common factor

for (i =1 ; i<= min(n1,n2); i++){
    if (n1 % i == 0 && n2 % i == 0 ){
        cout << i << " is the gcd";
    }
}

//a netter approach is to start loop from minimum of n1,n2 and then run the loop 
//till i> = 1 

//tc = O(min(n1,n2))


}