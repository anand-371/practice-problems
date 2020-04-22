#include<bits/stdc++.h>
using namespace std;
int coins[]={1,2,5,10,20,50,100,200,500,2000};
void change(int n)
{
    int i,dp[10][n+1],j;
    for(i=0;i<=n;i++)
    {
        dp[0][i]=i;
    }
    for(i=1;i<10;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(j>=coins[i])
            dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
     i=9;j=n;
    while(i>=0 && j>0)
    {
        if(dp[i][j]==dp[i-1][j])
        i=i-1;
        else
        {
            cout<<coins[i]<<" ";
            j=j-coins[i];
        }
    }
    
}
int main()
 {
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    cin>>n;
	    change(n);
	    cout<<endl;
	}
	return 0;
}