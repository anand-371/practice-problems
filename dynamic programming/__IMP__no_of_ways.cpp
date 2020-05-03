/*
Given a tile of size 1 x 4, how many ways you can construct a grid of size N x 4.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<cmath>
int min(int a,int b){
	if(a>b){return b;}
	return a;
}
int main(){
std::ios_base::sync_with_stdio(false); 
cin.tie(NULL);
int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		long long int dp[n+1];
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(i>=1&&i<=3)
				dp[i]=1;
			else if(i==4)
				dp[i]=2;
			else
				dp[i]=dp[i-1]+dp[i-4];
		}
		cout<<dp[n]<<endl;

}
} 
