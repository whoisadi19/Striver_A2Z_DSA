#include <bits/stdc++.h>
using namespace std;

//Q1 count the number of digits 


//my approach  #TC = O( log 10(w))
int main(){

int w = 123;
int i = 0;
while (w>0) {
    int last_digit = w % 10; //this step is not necessary as digit extraction is not required for counting 
    w = w / 10;
    i = i+1 ;
}

cout << i << " digits counted"<<endl;

//optimised way #TC = O(1)
int n = 10876;
int count = (int) (log10(n) + 1);

cout << count << endl;




return 0;
}

