/*
Search in Rotated Sorted Array
Given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You should search for target in nums and if you found return its index, otherwise return -1.
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 
*/
class Solution {
public:
int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if (nums[mid]==target)
            {
                return mid;
            }else if ((nums[start]<=target && target<=nums[mid])||((target<nums[mid] || target>nums[end]) && nums[mid]<=nums[end]))
            {
                end=mid-1;
            }else 
            {
                start=mid+1;
            }
        }
        return -1;
}
};
