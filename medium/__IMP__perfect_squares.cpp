/*
Perfect Squares
Write a program that determines the smallest number of square numbers that sum up to n.

Constraints

1 ≤ n ≤ 100,000
Example 1
Input
n = 4
Output
1
Explanation
4 is already the square of 2.

Example 2
Input
n = 17
Output
2
Explanation
16 + 1

Example 3
Input
n = 18
Output
2
Explanation
9 + 9

Intuition
DP approach.

dp[i] means how many perfect square numbers which sum to i. Hence, i is the upper limit.

Either the current dp[i] or the previous one plus one.

dp[0] = 0 
dp[1] = dp[0]+1 = 1
dp[2] = dp[1]+1 = 2
dp[3] = dp[2]+1 = 3
dp[4] = min(dp[4-1*1]+1, dp[4-2*2]+1) 
      = min(dp[3]+1, dp[0]+1)
      = 1				
dp[5] = min(dp[5-1*1]+1, dp[5-2*2]+1) 
      = min(dp[4]+1, dp[1]+1) 
      = 2

dp[n] = min(dp[n-i*i]+1),  n-i*i>=0&&i>=1
int solve(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

*/

int solve(int n) {
    std::vector<int> store;
    int number=1;
    int sq=1;
    while(sq<=n){
        store.push_back(sq);
        number++;
        sq=number*number;
    }
    
    int cols=n+1;
    std::vector<int>dp(cols,n);
    dp[0]=0;
    for (int i = 0; i < store.size(); ++i)
    {
            for (int j = store[i]; j <cols; ++j)
            {
                dp[j]=std::min(dp[j],1+dp[j-store[i]]);
            }
    }
    return dp[n];
}
