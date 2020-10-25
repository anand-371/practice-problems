/*
Find the element that appears once in sorted array
Given a sorted array arr[] of size N. Find the element that appears only once in the array. All other elements appear exactly twice. 

Example 1:

Input:
N = 11
arr[] = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65}
Output: 4
Explanation: 4 is the only element that 
appears exactly once.
 

Your Task:  
You don't need to read input or print anything. Complete the function findOnce() which takes sorted array and its size as its input parameter and 
returns the element that appears only once. 


Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)
*/
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int start=0;
        int end=n-1;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if (mid%2==0)
            {
                    if (arr[mid]==arr[mid+1])
                    {
                        start=mid+1;
                    }else{
                        end=mid-1;
                    }
            }else{
                if (arr[mid]==arr[mid-1])
                {
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return arr[start];
    }
};
