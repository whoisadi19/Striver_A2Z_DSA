#include <bits/stdc++.h>
using namespace std;

//my approach
int factorial (int i, int n) {
if (n <= 0){
return 1;
}
if (i>n) {
    return 1;
}
return  i * factorial( i+1, n);
}

//a better approach 
int fact (int n){
    if (n<=1) return 1;
    return n * fact(n-1);
}




int main (){
int n;
cin>>n;

cout << factorial(1, n)<< endl;
cout << fact(n)<< endl;

}

//my mistakes : mainly made mistakes in returning the function
//i need to work more on my functions i seem to forget basics