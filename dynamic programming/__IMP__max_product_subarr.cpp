/*
Maximum Product Subarray 
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
class Solution {
public:
    int max(int  a,int  b){
	    if(a>b){return a;}
	    return b;
	}
	int min(int a,int b){
	    if(a<b){return a;}
	    return b;
	}
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
        long long curr_max=arr[0];
        long long curr_min=arr[0];
        long long result=arr[0];
        for (int i = 1; i < n; ++i)
        {
            long long temp=curr_max;
            curr_max=max(arr[i],max(curr_max*arr[i],curr_min*arr[i]));
            curr_min=min(arr[i],min(temp*arr[i],curr_min*arr[i]));
            result=max(curr_max,result);
        }
        return result;
    }
};
