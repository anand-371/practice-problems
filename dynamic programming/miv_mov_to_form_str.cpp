/*
Given a string S, we need to write a program to check if it 
is possible to construct the given string S by performing any of the below operations any number of times. 
In each step, we can:

Add any character at the end of the string.
or, append the string to the string itself.
The above steps can be applied any number of times. We need to print the minimum steps required to form the string.

Input:
The first line contains an integer T, the number of test cases. For each test case, there is a string s which we
need to form. 
*/
#include <iostream>
#include<string.h>
using namespace std;
bool check(string s,int i){
    if(i%2!=0){return false;}
    int mid=i/2;
    for(int j=0;j<mid;j++){
        if(s[j]!=s[mid+j]){return false;}
    }
    return true;
}
int minmoves(string s){
    int n=s.length();
    int l[n];
    l[0]=1;
    for(int i=1;i<n;i++){
        if(check(s,i+1)==false){
            l[i]=l[i-1]+1;
        }else{
            l[i]=l[i/2]+1;
        }
    }
    return l[n-1];
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<minmoves(s);
	    cout<<endl;
	}
	return 0;
}