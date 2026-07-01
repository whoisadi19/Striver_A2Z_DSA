//functions 
//pass by reference and value

#include<bits/stdc++.h>
using namespace std;

//used to increase readability, repetition, modularity
//void functions
//return functions
//parameterised functions
//non parametrised function


//void (non parameterised)
//doesnt return anything
void printName() {
    cout <<"hey adi"<<endl;
}

//parameterised
void printBname(string name) {
    cout << "hey "<<name<<endl;
}

//take two nums and print its output
void twoSum(int a,int b){
    int c;
    c = a + b;
    cout<< c <<endl;
}

//return function
int sum(int a, int b){
    int c;
    c = a + b; 
    return c;
}

//pass by value
//when we pass a value to a function only the 
//copy of its value is passed in the parameter
//the original value remains intact
void doSomethingValue(string s) {
    s[0] = 't';
    cout << s << endl;
}

//pass by reference 
//we pass a value to the function the actual
//value gets passed and is modified 
//arrays always goes in as reference by default
//so & sign isnt needed for arrays
void doSomethingReference(string &s) {
    s[0] = 't';
    cout << s << endl;
}


int main() {
    string name;
    int a,b;

    printName();

    cin >> name;
    printBname(name);


    cin >> a >> b;
    twoSum(a,b);
    
    int res = sum(a,b);
    cout<<res<<endl;

//inbuilt functions

int minimum = min(a,b);
int maximum = max(a,b);
cout<< minimum << " " <<maximum;

    cout << endl;
    // Demonstration of pass by value and pass by reference
    string s = "raj";
    
    // Pass by value (original remains intact)
    doSomethingValue(s);
    cout << s << endl;
    
    // Pass by reference (original is modified)
    doSomethingReference(s);
    cout << s << endl;

    return 0;
}