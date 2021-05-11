/*
Remove Sublist to Reach Equilibrium
Given a list of integers nums and an integer k, you can remove any sublist at most once from the list.

Return the length of the longest resulting list such that the amount of numbers strictly less than k and strictly larger than k is the same.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [5, 9, 7, 8, 2, 4]
k = 5
Output
5
Explanation
If we remove the sublist [8] then we'd get [5, 9, 7, 2, 4] and there's two numbers [2, 4] that's smaller than 5 and two numbers [9, 7] larger than 5.

Example 2
Input
nums = [1, 2, 3]
k = 4
Output
0
Explanation
We need to remove the whole sublist to have the same amount of numbers greater than 4 as amount of numbers less than 4.
*/

int solve(vector<int>& nums, int k) {
    int n=nums.size();
    std::vector<int>prefix;
    prefix.push_back(0);
    int count=0;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i]>k)
        {
            count++;
        }else if (nums[i]<k)
        {
            count--;
        }
        prefix.push_back(count);
    }
    if (prefix.back()==0)
    {
        return n;
    }
    map<int,int>m;
    int ans=INT_MAX;
    for (int i = 1; i <=prefix.size(); ++i)
    {
        if (m[prefix[i]-prefix.back()]!=0 || prefix[i]-prefix.back()==0)
        {
            ans=std::min(ans,i-m[prefix[i]-prefix.back()]);
        }
        m[prefix[i]]=i;
    }
    if (ans==INT_MAX)
    {
        return 0;
    }
    return n-ans;
}
