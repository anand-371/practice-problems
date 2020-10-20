/*
Given a String, find the longest palindromic subsequence

Input:
The first line of input contains an integer T, denoting no of test cases. The only line of each test case consists of a string S(only lowercase)

Output:
Print the Maximum length possible for palindromic subsequence.

Constraints:
1<=T<=100
1<=|Length of String|<=1000
 

Examples:
Input:
2
bbabcbcab
abbaab
Output:
7
4
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int n=s.length();
        int dp[n+1][n+1];
        for (int i = 0; i <=n; ++i)
        {
            dp[i][i]=1;
        }
        for (int cl = 2; cl <=n; ++cl)
        {
            for (int i = 0; i < n-cl+1; ++i)
            {
                int j =i+cl-1;
                if (s[i]==s[j] && cl==2)
                {
                    dp[i][j]=2;
                }else if (s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }else{
                    dp[i][j]=std::max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        cout<<dp[0][n-1]<<endl;
    }
}




