/*
Longest Sublist with Absolute Difference Condition
Given a list of integers nums and an integer k, return the length of the longest sublist where the absolute difference between the largest and smallest element of the sublist is ≤ k.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 3, 5, 9]
k = 4
Output
3
Explanation
We pick [1, 3, 5] since the absolute difference is 4.
*/
int solve(vector<int>& nums, int k) {
    multiset<int>st;
    int left=0;
    int ans=0;
    int n=nums.size();
    for (int i = 0; i <n; ++i)
    {
        st.insert(nums[i]);
        while(abs(*st.rbegin()-*st.begin())>k){
            st.erase(st.lower_bound(nums[left++]));
        }
        ans=std::max(ans,i-left+1);
    }
    return ans;
}
