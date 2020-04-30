/*
Minimum Cost To Make Two Strings Identical
Given two strings X and Y, and two values costX and costY.
 We need to find minimum cost required to make the given two strings identical. We can delete characters from both the strings. The cost of deleting a character from string X is costX and from Y is costY. Cost of removing all characters from a string is same.

Input:

The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The first line of each test case contains integers X and Y denoting the value of costX and costY.

The second line of the test case contains the two strings X and Y.
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
int solve(string s1,string s2){
	int n1=s1.length();
	int n2=s2.length();
	int length=max(n1,n2);
	int dp[length+1][length+1];
	for (int i = 0; i <=length ; ++i)
	{
		dp[0][i]=0;
		dp[i][0]=0;
	}
	for (int i = 1; i <=n1; ++i)
	{
		for (int j = 1; j <=n2; ++j)
		{
			if (s1[i-1]==s2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n1][n2];



}
int main(){
	std::ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	string s1,s2,final;
	int t,cost1,cost2;
	cin>>t;
	while(t--){
	cin>>cost1>>cost2;
	cin>>s1>>s2;
	int res=solve(s1,s2);
	int tot_cost=0;
	tot_cost=((s1.length()-res)*cost1)+((s2.length()-res)*cost2);
	cout<<tot_cost<<endl;

	
	}
	return 0;
}