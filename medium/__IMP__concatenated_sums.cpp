/*
Concatenated Sums
You are given a list of non-negative integers nums. Return the sum of every concatenation of every pair of numbers in nums.
Note that pairs (i, j) and (j, i) are considered different.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [10, 2]
Output
1344
Explanation
We have the following concatenations:

nums[0] + nums[0] = 1010
nums[0] + nums[1] = 102
nums[1] + nums[0] = 210
nums[1] + nums[1] = 22
And its sum is 1344
*/
int solve(vector<int>& nums) {
    std::map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        string temp=to_string(nums[i]);
        m[temp.length()]++;

    }
    int total=0;
    for (int i = 0; i < nums.size(); ++i)
    {
        for(auto j:m){
            total+=(nums[i]*(j.second*pow(10,j.first)));
        }
        total+=(nums[i]*nums.size());
    }
    return total;
}
