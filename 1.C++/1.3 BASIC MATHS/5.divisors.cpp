//aim is to print all the divisors of the given input

#include <bits/stdc++.h>
using namespace std;

int main(){

int n;
cin>> n;
//tc = O(n)
for(int i=1; i<=n; i++){
    if (i%n == 0){
        cout << i;
    }
}


//better approach 

//we can run the loop only till sqrt N
//tc less than O(sqrt n)
// used i*i<=n instead i<sqrt(n)
vector<int> ls;
for(int i = 1; i*i <= n; i++ ){
    if(n%i==0) {
        ls.push_back(i);
        if(n/i != 1){
            ls.push_back(n/i);
        }

    }
}
sort(ls.begin(), ls.end());

for(auto it : ls) cout << it << " ";

    return 0;
}







