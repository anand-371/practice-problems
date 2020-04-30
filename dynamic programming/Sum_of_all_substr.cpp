/*
Sum of all substrings of a number
Given an integer S represented as a string, 
the task is to get the sum of all possible sub-strings of this string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
 Each test case contains a string S that represents a number.

Output:
For each test case, in a new line, print the required result.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 
#include <limits.h>
const int MAX = 100;
int maximum(int a,int b){
	if (a>b)
	{
		return a;
	}
	return b;
}
int toDigit(char ch) 
{ 
    return (ch - '0'); 
} 

int sumOfSubstrings(string num) 
{ 
    int n = num.length(); 
    int sumofdigit[n];  
    sumofdigit[0] = toDigit(num[0]); 
    int res = sumofdigit[0]; 
    for (int i = 1; i < n; i++) { 
        int numi = toDigit(num[i]);  
        sumofdigit[i] = (i + 1) * numi + 10 * sumofdigit[i - 1]; 
        res += sumofdigit[i]; 
    } 
    return res; 
} 
int main(){
	std::ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	long long int t,n,k,m;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		cout<<sumOfSubstrings(s)<<endl;

	}
	return 0;
}