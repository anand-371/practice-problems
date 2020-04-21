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
	    int arr[n];
	    int DP[n+1];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    DP[0]=arr[0];
	    DP[1]=arr[1];
	    for (int i = 2; i <=n; ++i)
	    {
	    	DP[i]=arr[i]+min(DP[i-2],DP[i-1]);
	    }
	    cout<<min(DP[n-1],DP[n-2])<<endl;

	}
	return 0;

}