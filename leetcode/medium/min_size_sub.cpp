/*
Minimum Size Subarray Sum
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0){return 0;}
        int left=0;
        int right=1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i]>=s)
            {
                return 1;
            }
        }
        int sum=nums[left]+nums[right];
        int mini=INT_MAX;
        while(true){

            if (sum<s)
            {       if (right==nums.size()-1)
                    {
                        break;
                    }
                    right++;
                    sum+=nums[right];
            }else{
                mini=std::min(mini,(right-left+1));
                sum-=nums[left];
                if (left==nums.size()-2)
                {
                    break;
                }
                left++;
            }
        }
        if(mini==INT_MAX){return 0;}
        return mini;
    }
};
