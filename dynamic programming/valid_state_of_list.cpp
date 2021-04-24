/*
Valid State of List
Given a list of integers nums, return whether every number can be grouped using one of the following rules:

You can form contiguous pairs (a, a)
You can form contiguous triplets (a, a, a)
You can form contiguous triplets (a, a + 1, a + 2)
Constraints

n ≤ 100,000 where n is the length of nums.
Example 1
Input
nums = [7, 7, 3, 4, 5]
Output
true
Explanation
We can group [7, 7] together and [3, 4, 5] together.

Example 2
Input
nums = [1, 3, 2]
Output
false
Explanation
We can't group [1, 3, 2] together.
*/
bool solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = true;
    for (int i = 2; i <= n; i++) {
        if (nums[i - 1] == nums[i - 2]) {
            dp[i] = dp[i] | dp[i - 2];
        }
        if (i >= 3 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3]) {
            dp[i] = dp[i] | dp[i - 3];
        }
        if (i >= 3 && nums[i - 3] + 2 == nums[i - 1] && nums[i - 2] + 1 == nums[i - 1]) {
            dp[i] = dp[i] | dp[i - 3];
        }
    }
    return dp[n];
}
