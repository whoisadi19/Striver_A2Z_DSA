#include <bits/stdc++.h>
using namespace std;


//Check if a number is Armstrong Number or not
//Problem Statement:Given an integer N, return true it is an Armstrong number otherwise return false.
//An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
int main() {
int n;
cin>> n;
int count = 0;
int tmp_n = n;
//lets start by counting number of digits and storing it for the power

while(tmp_n != 0 ){
    tmp_n = tmp_n/10;
    count = count + 1;
}
int t2_n = n;
int k = count;
int sum = 0;
//now we have to extract each digit, raise it to power of k and then add it with the rest
while (t2_n != 0){
    int last_digit = t2_n % 10;
    sum = sum + round(pow(last_digit, k));
    t2_n = t2_n/10; 
}

cout << "sum raised to power of digits is "<< sum << endl;
if( sum == n) { 
    cout<< "the number is armstrong";
}
else {
    cout << "not armstrong";
}


}