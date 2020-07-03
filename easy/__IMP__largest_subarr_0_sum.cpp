/*
Largest subarray with 0 sum
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Input:
The first line of input contains an element T denoting the number of test cases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains a number denoting the size of the array A. Then in the next line are space-separated values of the array A.

Output:
For each test case, the output will be the length of the largest subarray which has sum 0.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 104
-1000 <= A[i] <= 1000, for each valid i

Example:
Input
1
8
15 -2 2 -8 1 7 10 23

Output
5
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
