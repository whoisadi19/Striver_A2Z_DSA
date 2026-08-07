#include<bits/stdc++.h>
using namespace std;

void reversePrint(int N){

if (N < 1) return;
cout<< N << endl;
N--;

reversePrint(N);

}

int main(){
    int N;

    cout<< "Enter numbers to print in reverse: " <<endl;
    cin>> N;

    reversePrint(N);
}