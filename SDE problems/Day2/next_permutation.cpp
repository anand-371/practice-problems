/*
 Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>test=nums;
        int i,l;
        for (i =nums.size()-2; i >=0; i--)
        {
               if (nums[i]<nums[i+1])
               {
                   break;
               }
        }
        if (i<0)
        {
             std::reverse(nums.begin(),nums.end());
        }else{
            for (l = nums.size()-1; l >i; l--)
            {
                if (nums[l]>nums[i])
                {
                    break;
                }
            }
            swap(nums[i],nums[l]);
        }
        std::reverse(nums.begin()+i+1,nums.end());
    if(nums==test){
        sort(nums.begin(),nums.end());
    }
    }
};
