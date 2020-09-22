/*
Find the length of largest subarray with 0 sum
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 104
-1000 <= A[i] <= 1000, for each valid i
*/
int maxLen(int a[], int n) {
    // Your code here
    int sum=0;
    map<int,int>mp;
    int ans=0,j=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==0)
            ans=i+1;
        else
        {
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
                
            }
            else
            {
                j=mp[sum];
                ans=max(ans,i-j);
                
            }
        }
            
    }
    return ans;
}
