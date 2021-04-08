/*
Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
class Solution {
public:
void back_track(vector<vector<int>>&store,vector<bool>&visited,vector<int>&nums,vector<int>&temp){
    if (temp.size()==nums.size())
    {
        store.push_back(temp);
    }
    for (int i = 0; i <nums.size(); ++i)
    {
            if (visited[i]==true)
            {
                temp.push_back(nums[i]);
                visited[i]=false;
                back_track(store,visited,nums,temp);
                visited[i]=true;
                temp.pop_back();
            }
    }
    return;
}

vector<vector<int>> permute(vector<int>& nums) {
    std::vector<vector<int>>store;
    std::vector<bool>visited(nums.size(),true);
    vector<int>temp;
    back_track(store,visited,nums,temp);
    return store;

    }
};
