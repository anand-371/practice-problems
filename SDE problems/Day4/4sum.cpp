/*
4Sum
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=0;
        std::vector<vector<int>> v;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {   int temp_target=target-nums[i]-nums[j];
                left=j+1;
                right=n-1;
                while(left<right){
                    if (nums[left]+nums[right]>temp_target)
                    {
                        right--;
                    }else if (nums[left]+nums[right]<temp_target)
                    {
                        left++;
                    }else{
                        std::vector<int> temp_quad;
                        temp_quad.push_back(nums[i]);
                        temp_quad.push_back(nums[j]);
                        temp_quad.push_back(nums[left]);
                        temp_quad.push_back(nums[right]);
                        v.push_back(temp);
                    
                     while(left<right && nums[left]==temp_quad[2]){left++;}
                     while(left<right && nums[right]==temp_quad[3]){right--;}
                 }
                }
                while(j<n-1 && nums[j+1]==nums[j]){j++;}
            }
            while(i<n-1 && nums[i+1]==nums[i]){i++;}
        }
        return v;
    }