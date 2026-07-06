#include <bits/stdc++.h>
using namespace std;

int main(){

    //digit extraction (reversed order)
    int w = 7789;
    //we will use module '%' operator
    //it divides no. by something and then returns the remainder
    //ex: 7789 % 10 = 9

    //for digit extraction we are going to use modulo and divide in combination
    //the algo for digit extraction goes like:
    //1) first use the modulo operator on number lets say X and extract the last digit 
    //2) store the last digit 
    //3) now simply divide the number X from 10, it will remove the last digit
    //4) if you started with n digit number, now you have n-1 digit number
    //5) repeat the whole process

    while (w>0) {
        int last_digit = w % 10;
        w = w / 10 ;
        cout << last_digit << endl; 
    }
    return 0;
}