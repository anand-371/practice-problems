/*
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"
*/

string Solution::longestPalindrome(string A)
{
int n=A.length(),i,j,k,start=0,len=1;
bool dp[n][n];
memset(dp,0,sizeof(dp));
for(i=0;i<n;i++)
{
    dp[i][i]=true;
}
for(i=0;i<n-1;i++)
{
    if(A[i]==A[i+1])
    {
        dp[i][i+1]=true;
        if(len<2)
        {
            len=2;
            start=i;
        }
    }
}
for(k=3;k<=n;k++)
{
    for(i=0;i<=n-k;i++)
    {
        j=i+k-1;
        if(A[i]==A[j] && dp[i+1][j-1]==true)
        {
            dp[i][j]=1;
            if(len<k)
        {
        len=k;
        start=i;
        }
    }
    }
}
    return A.substr(start,len);
}
