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
