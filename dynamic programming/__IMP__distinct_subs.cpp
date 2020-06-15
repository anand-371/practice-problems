/*Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It's guaranteed the answer fits on a 32-bit signed integer.

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
    */
    class Solution {
public:
    int numDistinct(string s, string t) {
        long long int n=s.length();
        long long int m=t.length();
        long long int arr[n+1][m+1];
        arr[0][0]=1;
        for(int i=1;i<=n;i++){
        	arr[i][0]=1;
            }
        for (int i = 1; i <=m; ++i)
        {
        	arr[0][i]=0;
        }
        for (int i = 1; i <=n; ++i)
        {
        	for (int j = 1; j <=m; ++j)
        	{
        		if (s[i-1]==t[j-1])
        		{
        			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        		}else{
        			arr[i][j]=arr[i-1][j];
        		}
        	}
        }
        return arr[n][m];
    }
};
