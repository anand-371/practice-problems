/*
Palindromic Substrings
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

class Solution {
public:
    int countSubstrings(string s) {
        int dp[s.length()][s.length()];
        int n=s.length();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                    dp[i][j]=0;
            }
        }
        int count=0;
        for (int i = 0; i < n; ++i)
        {
            dp[i][i]=1;
            count++;
        }
        for(int i=0;i<n-1;i++) 
            if(s[i]==s[i+1]) {
                dp[i][i+1] = 1; 
                count++;
            }
        for(int len=3;len<=n;len++) {  
            for(int i=0;i<n-len+1;i++) {
                int j = i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1])  { 
                    dp[i][j] = true;
                    count++;
                }
            }
        }
    return count;        
    }
};
