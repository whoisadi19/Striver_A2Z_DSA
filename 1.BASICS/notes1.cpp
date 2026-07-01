#include <bits/stdc++.h>
using namespace std;
int main(){
int x,y;
//IO

string s1,s2;
cout<< "Hey Aditya!!" <<endl << "hey sona" <<endl ;
cin >> x >> y;
cout << "the value of x is " << x << endl; 
cout << "the value of y is " << y << endl; 

//String

cin>> s1 >> s2;
cout<< s1 << " " << s2<< endl;
cin >> ws;
string str;
getline (cin, str);
cout <<str<<endl;


string g = "Aditya";
int len = g.size();
g[len-1] = 'z';
cout<< g[len-1]<<endl;
cout << g << endl; 



//if else

int z;

cout<<"Enter your age : "<<endl;
cin>> z;

if (z>18){
    cout<<"You are an adult"<<endl;
}
else {
    cout<<"You are not an adult"<<endl;
}

//switch

int day;

cin>>day;
switch(day) {
    case 1:
        cout <<"Monday";
        break;
    case 2:
        cout <<"Tuesday";
        break;
    case 3:
        cout <<"Wednesday";
        break;
    default : 
        cout<< "Invalid";
}
cout << "Check"<<endl;

//Arrays and Strings Basics

int arr[4];

cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];

cout<<arr[3];

//2D array

 int brr [3][5];
 //3 rows and 5  columns 
 brr [1][3] = 78;
 cout<< brr [1][3];






return 0;
}
