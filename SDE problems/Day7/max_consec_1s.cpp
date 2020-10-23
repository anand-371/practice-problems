/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_til_now=0;
    int counter=0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i]==1)
            {
                counter++;
            }else{
                counter=0;
            }
            max_til_now=std::max(max_til_now,counter);
        }
        return max_til_now;
    }
};
