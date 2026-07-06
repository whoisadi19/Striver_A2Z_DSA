#include <bits/stdc++.h>
using namespace std;
int main() {

int n;
cin >> n;
int tmp_n = n;
int rev_num = 0;

if (n<0) {
    cout<< "not palindrome";
}
else {
while (tmp_n != 0){
int last_digit = tmp_n % 10;
rev_num = (rev_num *10) + last_digit ;
tmp_n = tmp_n / 10;
}
if (rev_num ==n){
    cout << "palindrome";
}
else {
    cout << "not palindrome";
}
}
return 0;
}