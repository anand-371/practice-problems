/*
Maximum Sum Removing K Numbers From Ends
You are given a list of integers nums and integer k. Return the maximum sum of elements that you can remove given that you must pop exactly k times,
where each pop can be from the left or the right end.

Constraints

k ≤ n ≤ 100,000 where n is length of nums.
Example 1
Input
nums = [1, 3, 4, 2, 0]
k = 2
Output
4
Explanation
We take the 1 and the 3

Example 2
Input
nums = [3, 1, 1, 1, 13, -1, 0]
k = 4
Output
15
Explanation
We take 3 from the left and 0, -1, 13 from the right.
*/
int solve(vector<int>& nums, int k) {
    int total_sum=0;
    int window_sum=0;
    int n=nums.size();
    for (int i = 0; i < nums.size(); ++i)
    {
            if (i<n-k)
            {
                    window_sum+=nums[i];
            }
            total_sum+=nums[i];
    }
    int window_end=n-k;
    int window_start=0;
    int min_value=window_sum;
    cout<<window_sum<<endl;
    while(window_end<n){
        window_sum-=nums[window_start];
        window_sum+=nums[window_end];
        cout<<window_sum<<endl;
        min_value=std::min(window_sum,min_value);
        window_start++;
        window_end++;
    }
    return total_sum-min_value;

}
