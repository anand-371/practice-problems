/*
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. 
The possible operations are:

Insert
Remove
Replace
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.

Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.
*/
// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
		int LCS(string s1, string s2){
   int n1=s1.length();
	int n2=s2.length();
	int length=max(n1,n2);
	int dp[length+1][length+1];
	for (int i = 0; i <=n1; ++i)
	{
		for (int j = 0; j <=n2; ++j)
		{   if(i==0){
		    dp[i][j]=j;
	    	}
	    	else if(j==0){
		    dp[i][j]=i;
	    	}
			else if (s1[i-1]==s2[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+std::min(std::min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
			}
		}
	}
	return dp[n1][n2];
}

int editDistance(string s, string t)
        {
            return LCS(s,t);

        }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends
