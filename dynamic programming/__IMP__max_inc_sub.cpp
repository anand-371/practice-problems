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
	    for (int i = 0; i < n; ++i)
	    {
	    	DP[i]=1;
	    }
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for (int i = 0; i < n; ++i)
	    {
	    	for (int j = 0; j < i; ++j)
	    	{
	    		if (arr[i] > arr[j] && DP[i]<DP[j]+1)
	    		{
	    			DP[i]=DP[j]+1;
	    		}
	    	}
	    }
	    int max=DP[0];
	    for (int i = 1; i < n; ++i)
	    {
	    	if (DP[i]>max)
	    	{
	    		max=DP[i];
	    	}
	    }
	    cout<<max<<endl;
	}
	return 0;

}