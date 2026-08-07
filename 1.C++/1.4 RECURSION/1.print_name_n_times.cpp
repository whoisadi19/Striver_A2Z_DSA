#include<bits/stdc++.h>
using namespace std;
int cnt = 0;

void printName(int N){
    if (cnt == N){
        return ;
    }
    cout << "Adi" << endl;
    cnt++;
    printName(N);
}

int main() {
    int N;
    cout << "enter value for N: " << endl;
    cin >> N;
    printName(N);
    return 0;
}


//mistakes :
/* I declared variable for count as *count* which created conflict as it 
is a standard package that comes with the library i imported, so use counter as cnt or 
something else

then i declared int N as a global variable and re-declared it while passing it to the 
printName function which created issues
*/


/*
strivers approach :

#include <bits/stdc++.h>
using namespace std;

void printName(int i, int n) {
    if (i > n) return;
    cout << "Adi" << endl;
    printName(i + 1, n);
}

int main() {
    int n;
    cout << "enter value for N: " << endl;
    cin >> n;
    printName(1, n);
    return 0;
}
*/
