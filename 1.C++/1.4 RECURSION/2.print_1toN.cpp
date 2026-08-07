#include<bits/stdc++.h>
using namespace std;

//the task is to print  1 to N linearly using 
//recursive functions

//my approach:
int cnt = 1;
void printNum(int n){
if (cnt > n) return;
cout<< cnt <<endl ; 
cnt++;
printNum(n);
}


//better approach: passing counter as variable itself into the recursive function

void optimal(int i, int n){

if (i > n) return;
cout << i << endl;
optimal(i+1, n);

}



int main() {
int n;
cout << "enter the numbers to print: "<< endl;
cin>> n;
//printNum(n);
optimal(1,n);
}

//mistake i did: I initialised the counter  = 0 inside the recursive function
//due to which the counter reset to 0 after each loop hence causing an infinite loop and stack overflow
