#include <bits/stdc++.h>
using namespace std;

//Q2 Reverse a number


//my approach (nil)
// solution   
int main(){
int n;
cin>> n;

long long rev_num = 0;
//n!0 instead of n>0 as to ensure that it reverses even negative numbers
while(n!0)  {
int last_digit = n % 10; 
n = n / 10 ;
rev_num = (rev_num *10) + last_digit ;
}
 // LeetCode Rule: Return 0 if the reversed number overflows a 32-bit signed int
 if (rev_num > INT_MAX || rev_num < INT_MIN) {
  return 0;
 }
cout << rev_num ; 

}