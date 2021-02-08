/*
Element with left side smaller and right side greater 
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

 

Example 1:

Input:
N = 4
A[] = {4, 2, 5, 7}
Output:
5
Explanation:
Elements on left of 5 are smaller than 5
and on right of it are greater than 5.
 

Example 2:

Input:
N = 3
A[] = {11, 9, 12}
Output:
-1
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findElement() which takes the array A[] and its size N as inputs and returns the required element. If no such element present in array then return -1.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/
int findElement(int arr[], int n) {
    std::vector<int>left;
    std::vector<int> right;
    int left_max=arr[0];
    for (int i = 0; i < n; ++i)
    {
        left_max=std::max(left_max,arr[i]);
        left.push_back(left_max);
    }
    int right_min=arr[n-1];
    for (int i =n-1; i>=0;i--)
    {
        right_min=std::min(right_min,arr[i]);
        right.push_back(right_min);
    }
    std::reverse(right.begin(),right.end());
    for (int i = 1; i < n-1; ++i)
        {
            if (arr[i]>=left[i] && arr[i]<=right[i])
            {
                return arr[i];
            }
        }
    return -1;    
}
