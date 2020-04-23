/*Count of strings that can be formed using a, b and c under given constraints
Given a length n, count the number of strings of length n that can be made 
using ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed.

Input:
The first line of input contains an integer T denoting the number of
 test cases. Then T test cases follow. The first line of each test 
 case contains an integer N denoting the length of the string.

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath>
int min(int a,int b){
	if(a>b){return b;}
	return a;
}
int count(int dp[][2][3],int n,int bc=1,int cc=2){
	if (bc < 0 || cc < 0) return 0; 
    if (n == 0) return 1; 
    if (bc == 0 && cc == 0) return 1;
	if (dp[n][bc][cc]!=-1)
	{
		return dp[n][bc][cc];
	}
	else{
	int final= count(dp,n-1,bc,cc);
	final+=count(dp,n-1,bc-1,cc);
	final+=count(dp,n-1,bc,cc-1);
	dp[n][bc][cc] = final;
	return final;
	}
}
int main(){
	std::ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int t;
	cin>>t;
	int n;
	while(t--){
	    cin>>n;
	    int dp[n+1][2][3];
	    memset(dp, -1, sizeof(dp)); 
	    cout<<count(dp,n);	
	}
	return 0;

}