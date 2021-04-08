/*
 Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

class Solution {
public:
    void back_track(vector<vector<int>>&store,vector<int>&nums,int index,vector<int>&temp){
    store.push_back(temp);
    for (int i = index; i <nums.size(); ++i)
    {
        temp.push_back(nums[i]);
        back_track(store,nums,i+1,temp);
        temp.pop_back();
    }
    return;
}
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>store;
        std::vector<int>temp;
        back_track(store,nums,0,temp);
        return store;
    }
};
