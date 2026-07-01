//PAIRS

#include <bits/stdc++.h>
using namespace std;

int main(){
//as we already saw there are 2 types of functions, one that returns nothing 
//and one that has a return type moving onto next topic here we will discuss about 
//some standard libraries of cpp, first lets learn about pairs

//part of utility library of cpp
//the method of making pair is 
// pair <data type,data type> pairname = {data,data}

//making a pair
pair<int, int> p = {1,3};
cout << p.first << " " << p.second<< endl; 

//another way of storing pairs
pair<int, pair<int,int>> p1 = {8,{4,7}};
cout<<p1.first << " "<< p1.second.first << " " << p1.second.second<< endl;

//making an array using pair
pair<int, int> arr[] = {{1,2}, {2,5}, {5,1}};
cout<< arr[1].second<< endl;


//Lexicographical comparison 
//pairs have built in operators which can be used for sorting pairs 
//they compare first elements at first if they are equal they compare second
//case 1 : first numbers are different
pair<int, int> a = {1,99};
pair<int, int> b = {2,3};
if (a<b){
    cout << "a is smaller than b" << endl;
}

//case 2: first numbers are same, then compares by second number
pair<int, int> c = {5,10};
pair<int, int> d = {5,3};
if(c>d){
    cout<< "c is bigger than d" << endl;
}




}