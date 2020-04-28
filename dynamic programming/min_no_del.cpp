/*
Minimum Deletions
Given a string of S as input.
 Your task is to write a program to remove or delete minimum number of characters from the string so that the resultant string is palindrome.

Note: The order of characters in the string should be maintained.

Input:
First line of input contains a single integer T which denotes the number of test cases. 
Then T test cases follows. First line of each test case contains a string S.

Output:
For each test case, print the deletions required to make the string palindrome.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 
#include <limits.h>
int max(int a,int b){
	if (a>b)
	{
		return a;
	}
	return b;
}
int solve(string s,int n){
	int dp[n+1][n+1]={0};
	for (int i = 0; i <=n; ++i)
	{
		dp[i][i]=1;

	}
	for (int i = 0; i <=n; ++i)
	{
		if (s[i]==s[i+1])
		{
			dp[i][i+1]=2;
		}else{
			dp[i][i+1]=1;
		}
		
	}
	int j=0;
	for (int k =3; k <=n; ++k)
	{
		for (int i = 0; i < n-k+1; ++i)
		{
			 j=i+k-1;
			 if (s[i]==s[j])
			 {	
			 	dp[i][j]=2+dp[i+1][j-1];
			 }else{
			 	dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
			 }
		}
	}
	cout<<s.length()-dp[0][n]<<endl;

}
int main(){
	std::ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	string s;
	int t;
	cin>>t;
	while(t--){
	cin>>s;
	solve(s,s.length());
	
	}
	return 0;
}