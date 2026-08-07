#include<bits/stdc++.h>
using namespace std;

void backtrack(int i,int N){
if (i<1){
    return;
}
cout<< i<< endl;
backtrack(i-1,N);
}

int main(){
int N;
cin>> N;
backtrack(N,N);

}