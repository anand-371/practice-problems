/*
Rod Cutting
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input:
First line consists of T test cases. First line of every test case consists of n, denoting the size of array.
 Second line of every test case consists of price of ith length piece.
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price[],int n){
    int dp[n+1]={0};
    
    for(int i=1;i<=n;i++){
        int best=0;
        for(int cut=1;cut<=n;cut++){
            if(i-cut>=0)
            best = max(best,price[cut]+dp[i-cut]);
        }
        dp[i]=best;
    }
    return dp[n];
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int price[n + 1];
	    for(int i=1;i<=n;i++){
	        cin>>price[i];
	    }
	    cout<<maxProfit(price,n)<<endl;
	}
	return 0;
}