#include <bits/stdc++.h>
using namespace std;
//single pointer
void rev(int i, int arr[], int n){
    if (i>= n/2)
    return;
    swap (arr[i], arr[n-i-1]);
    rev(i+1, arr, n);
}
//two pointer recursive approach

void reversal(int l, int r, int arr[]){
if (l>= r) return;

swap(arr[l], arr[r]);
reversal(l+1,r-1, arr);

}




int main() {
int n;
cout<< "enter no. of elements: " << endl;
cin >> n;
int arr[n];
cout<< "enter elements of array: " << endl;
for (int i=0; i<n; i++){
    cin >> arr[i];
}
rev(0,arr, n);
for (int i =0; i<n; i++){
cout << arr[i]<endl;
}

reversal(0,n-1,arr);
for (int i =0; i<n; i++){
cout << arr[i] <<endl;
}
}