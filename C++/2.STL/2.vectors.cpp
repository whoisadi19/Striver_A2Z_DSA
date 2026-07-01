//VECTORS

#include <bits/stdc++.h>
using namespace std;
int main (){

//these are like array but with fundamental differences
//ARRAYS - size cant be changes i.e its size is constant
//VECTOR - Dynamic in nature, that is its size can be changed later, specially
//helpful when the size isnt known

//making vector

vector<int> v; 
//this initialises an empty vector v which currently has no elements


//methods of storing data in vector 

v.push_back(1); // stores 1 in the vector;
v.emplace_back(2); //Dynamically increases the size of container, faster than push back
//right now v looks something like {1,2}
//both pushback and emplaceback can only store one element at a time

//for storing pairs in vector
vector <pair<int, int>> v2;
v2.push_back({3,4});
//instead of this if we write emplace back it automatically asumes the input to be a pair
v2.emplace_back(5,6);

cout << v[0] << " " << v[1] << endl;
cout <<  v2[0].first << " " << v2[0].second << endl;
cout << v2[1].first << " " << v2[1].second << endl;




//more ways of initialising vectors

vector<int> a (5,100); //makes {100,100,100,100,100}
vector<int> b (5); // makes {0,0,0,0,0} that is 5 zeros
vector<int> c (5,20); //makes {20,20,20,20,20}
vector<int> d(c); //copies the vector c into d
//increasing size of vector using push_back
b.push_back(1) ; //{0,0,0,0,0,1} now




//WAYS OF ACCESSING VECTORS
//lets begin with making vector e

vector<int> e = {10,20,30,40,50,60,70};

//now to look at the value stored there are various ways
//method 1 using index
cout << e[0] << " " << e[1]<< endl; //prints the values at 0th and 1st index
//method 2
cout <<e.at(2) << " " << e.at(3) << endl ;


//ITERATORS

//Iterators points to the address of the memory where our target data is stored
vector<int> f = {20,10,15,6,7};

//the syntax of writing an iterator is
//container type :: iterator iterator_name ;
vector<int> :: iterator it = f.begin(); //here f.begin points to the memory addres of the first element
// '*' can be used to access the data stored at the pointed iterator location
cout<< *it << endl;
//moving the iterator
it++;
cout << *it << endl;
it--;
cout << *it <<endl;


//shortcut
vector<int> :: iterator ia = f.begin(); 
//writing this over and over again could be exhaustive so instead use AUTO
auto ib = f.begin(); 
//automatically figures out the right container for our iterator



//Some important vector operations 

vector<int> g = {1,2,3,4,5};

cout << *g.begin() << endl; //points to the memory location of the first element
cout<< *g.rbegin() <<endl; // basically treats {1,2,3,4,5} as {5,4,3,2,1} 
// and points to the first element of the reversed container
// or in simple words points to the last element of the normal container

//cout << *g.end () << endl; // points to the memory location right after the last element
//cout<< *g.rend() <<endl; //reverse end, basially points at element right before the first element
//WARNING:  never try to print end or rend as it is out of bounds and reverse garbage value

//printing elements of a vector using loops

//method 1 

for(vector<int> :: iterator ic = g.begin() ; ic != g.end() ; ic++ ){
    cout << *ic << " ";
    cout << endl;
}

//this same can be done using auto for cleaner code

for(auto id = g.begin(); id != g.end(); id++){
    cout << *id << " ";
    cout<< endl;
}

//even cleaner , its a for each loop, here ig is not an iterator its the actual value
for (auto ig : g ){
    cout << ig << " " << endl;
}


}