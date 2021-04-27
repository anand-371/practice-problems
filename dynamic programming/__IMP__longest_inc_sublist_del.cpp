/*
Longest Contiguously Strictly Increasing Sublist After Deletion
Given a list of integers nums, return the maximum length of a contiguous strictly increasing sublist if you can remove one or zero elements from the list.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [30, 1, 2, 3, 4, 5, 8, 7, 22]
Output
7
Explanation
If you remove 8 in the list you can get [1, 2, 3, 4, 5, 7, 22] which is the longest, contiguous, strictly increasing list.
*/
int max_inc(vector<int>nums){
    int count=1;
    int max_count=1;
    int n=nums.size();
    for (int i = 0; i < n; ++i)
    {       
            if (nums[i+1]>nums[i])
            {
                count++;
            }else{
                count=1;
            }
            max_count=std::max(max_count,count);
    }
    return max_count;
}

int solve(vector<int>& nums) {
    int n=nums.size();
    if(n==0){return 0;}
    if(n==1){return 1;}
    std::vector<int>pre(n,0);
    std::vector<int>post(n,0);
    pre[0]=1;
    post[n-1]=1;
    for (int i = 1; i < n; ++i)
    {
            if (nums[i]>nums[i-1])
            {
                pre[i]=pre[i-1]+1;
            }else{
                pre[i]=1;
            }
    }
    for (int i = n-2; i>=0;i--)
    {
        if (nums[i]<nums[i+1])
        {
                post[i]=post[i+1]+1;
        }else{
            post[i]=1;
        }
    }
    int max_value=0;
    max_value=std::max(max_value,max_inc(nums));
    for (int i = 1; i <=n-2; ++i)
    {
            if (nums[i-1]<nums[i+1])
            {
                max_value=std::max(max_value,pre[i-1]+post[i+1]);
            }
    }
    return max_value;
}
