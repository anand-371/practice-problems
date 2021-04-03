/*
Fixed Point

Given a list of unique integers nums sorted in ascending order, return the minimum i such that nums[i] == i. If there's no solution, return -1.

This should be done in \mathcal{O}(log(n))O(log(n)) time.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [-5, -2, 0, 3, 4]
Output
3
Explanation
Both nums[3] == 3 and nums[4] == 4 but 3 is smaller.

Example 2
Input
nums = [-5, -4, 0]
Output
-1
Explanation
There's no i such that nums[i] = i.
*/
int solve(vector<int>& nums) {
    if(nums.size()==1 && nums[0]==0){return 0;}
    int left=0;
    int right=nums.size()-1;
    int flag=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if (mid==nums[mid])
        {   
            flag=mid;
            right=mid-1;
        }else if (mid<nums[mid])
        {
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return flag;
}
