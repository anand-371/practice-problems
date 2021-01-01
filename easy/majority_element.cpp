/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
    int check_for_majority(vector<int>& nums,int target){
    int count=0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i]==target)
        {
             count++;
        }
    }
    if (count>(nums.size()/2))
    {
        return 1;
    }
    return 0;
}
int master_majority(vector<int>& nums){
    int majority=0;
    int count=0;
    for (int i = 0; i < nums.size(); ++i)
    {
            if (nums[majority]==nums[i])    
            {
                count++;
            }else{
                count--;
            }
            if (count==0)
            {
                majority=i;
                count=1;
            }
    }
    return nums[majority];

}
int majorityElement(vector<int>& nums) {
     int cand=master_majority(nums);
     if (check_for_majority(nums,cand))
     {
         return cand;
     }
     return -1;
    }
};
