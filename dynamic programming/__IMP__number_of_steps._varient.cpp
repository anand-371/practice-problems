/*
A Flight of Stairs Sequel

You are given positive integers n and k. You are currently at stair 0 and want to climb to stair n. You can either climb 1, 2, or 3 stairs at a time, but you can only climb 3 stairs at most k times.

Return the number of ways to climb to the nth stair. The answer is guaranteed to fit in a 32-bit signed integer.

Constraints

n ≤ 37
Example 1
Input
n = 4
k = 1
Output
7
Explanation
Here are the different ways we can climb the stairs:

[1, 1, 1, 1]
[2, 1, 1]
[1, 2, 1]
[1, 1, 2]
[2, 2]
[3, 1]
[1, 3]
Example 2
Input
n = 3
k = 0
Output
3
Explanation
Here are the different ways we can climb the stairs:

[1, 1, 1]
[2, 1]
[1, 2]
Note that we can't climb 3 stairs at once since k = 0
*/
int dp[38][38];

int findAll(int n, int k) {
    if (n == 0) {
        return 1;
    }
    if (dp[n][k] != -1) {
        return dp[n][k];
    }

    int op1 = 0, op2 = 0, op3 = 0;
    if (n >= 1) {
        op1 = findAll(n - 1, k);
    }
    if (n >= 2) {
        op2 = findAll(n - 2, k);
    }
    if (n >= 3 && k >= 1) {
        op3 = findAll(n - 3, k - 1);
    }
    return dp[n][k] = op1 + op2 + op3;
}
int solve(int n, int k) {
    for (int i = 0; i <= 37; i++) {
        for (int j = 0; j <= 37; j++) {
            dp[i][j] = -1;
        }
    }
    return findAll(n, k);
}
