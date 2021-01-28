/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [0]
Output: 0
*/
class Solution {
public:
int dynamic(vector<int>nums,int l,int r){
    int prev2=0;
    int prev1=0;
    int max=0;
    for (int i = l; i <r; ++i)
    {
            max=std::max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=max;
    }
    return max;
}

int rob(vector<int>& nums) {
     if (nums.size()==0)
    {
        return 0;
    }else if (nums.size()==1)
    {
        return nums[0];
    }else if (nums.size()==2)
    {
        return std::max(nums[0],nums[1]);
    }
    return std::max(dynamic(nums,0,nums.size()-1),dynamic(nums,1,nums.size()));

    }
};
