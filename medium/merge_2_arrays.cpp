/*
Merge Without Extra Space
Given two sorted arrays arr1[] and arr2[] of sizes N and M in non-decreasing order. Merge them in sorted order without using any extra space.
Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
 

Example 1:

Input: 
N = 4, arr1[] = [1 3 5 7] 
M = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.
Example 2:

Input: 
N = 2, arr1[] = [10, 12] 
M = 3, arr2[] = [5 18 20]
Output: 
arr1[] = [5 10]
arr2[] = [12 18 20]
Explanation:
After merging two sorted arrays 
we get 5 10 12 18 20.


Your Task:
You don't need to read input or print anything. You only need to complete the function merge() that takes arr1, arr2, N and M as input parameters and modifies them in-place so that they look like the sorted merged array when concatenated.
 

Expected Time Complexity:  O((n+m) log(n+m))
Expected Auxilliary Space: O(1)
 

Constraints:
1 <= X, Y <= 5*104
0 <= arr1i, arr2i <= 109

*/
void merge(int arr1[], int arr2[], int n, int m) 
{ 
    int x=n-1;
    int y=0;
    while(x>=0 && y<m){
        if (arr1[x]>arr2[y])
        {
            int temp=arr1[x];
            arr1[x]=arr2[y];
            arr2[y]=temp;
            y++;
            x--;
        }else{
            x--;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}
