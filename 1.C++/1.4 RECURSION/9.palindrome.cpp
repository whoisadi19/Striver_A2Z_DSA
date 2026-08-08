#include<bits/stdc++.h>
using namespace std;
//aim is to check if a string is palindrome or not 
bool palindrome(int i,string &s){
if (i>= s.size()/2) return true;

if (s[i] != s[s.size() - i - 1]) return false;

return palindrome(i+1, s);

}

int main(){

string s = "madam";
cout << boolalpha << palindrome(0, s);


return 0;
}

/*
lc submission 1:
class Solution {
private:
bool check(int i, string &cstr){
if (i >= cstr.size() /2 ) return true;
if (cstr[i] != cstr[cstr.size()-i-1]) return false;
return check(i+1, cstr); 

}
public:
    bool isPalindrome(string s) {
   
 string  cleanStr = "";
        for (char ch:s){
            if (isalnum(ch)){
                cleanStr =  cleanStr + (char)tolower(ch);
            }
        }

 return check(0, cleanStr);

    }
}; reuslt : memory limit exceeded
*/

/*
accepted :
class Solution {

public:
    bool isPalindrome(string s) {
   
 string  cleanStr = "";
        for (char ch:s){
            if (isalnum(ch)){
                cleanStr += (char)tolower(ch);
            }
        }
int i = 0;
int n = cleanStr.size()-1;

 while (i<n) {
    if (cleanStr[i] != cleanStr[n] ) return false;
    i++;
    n--;
 }
return true;

    }
};

note : in the cleaning function 
using cleanStr = cleanStr + tolower(ch);
was causing memory limit to exceed
so i used cleanStr += tolower(ch); as it 
modifies the string in place without creating
temporary string copies   
*/