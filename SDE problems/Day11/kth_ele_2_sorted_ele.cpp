/*
K-th Element of Two Sorted Arrays
Given two sorted arrays A and B of size M and N respectively and an element k. The task is to find the element that would be at the k’th
position of the final sorted array.

Input:
First line consists of test cases T. First line of every test case consists of 3 integers N, M and K, denoting M number of elements in A,
N number of elements in B and kth position element. Second and Third line of every test case consists of elements of A and B respectively.

Output:
Print the element at the Kth position.

Constraints:
1 <= T <= 200
1 <= N, M <= 106
1 <= Ai, Bi <= 106
1 <= K <= N+M

Example:
Input:
1
5 4 5
2 3 6 7 9
1 4 8 10

Output:
6

Explanation:
Testcase 1: Element at 5th position after merging both arrays will be 6.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kth(int *arr1, int *arr2, int *end1, int *end2, int k) 
{ 
    if (arr1 == end1) 
        return arr2[k]; 
    if (arr2 == end2) 
        return arr1[k]; 
    int mid1 = (end1 - arr1) / 2; 
    int mid2 = (end2 - arr2) / 2; 
    if (mid1 + mid2 < k) 
    { 
        if (arr1[mid1] > arr2[mid2]) 
            return kth(arr1, arr2 + mid2 + 1, end1, end2, 
                k - mid2 - 1); 
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2, 
                k - mid1 - 1); 
    } 
    else
    { 
        if (arr1[mid1] > arr2[mid2]) 
            return kth(arr1, arr2, arr1 + mid1, end2, k); 
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k); 
    } 
} 

int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int arr1[n];
        int arr2[m];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr1[i];
        }
        for (int i = 0; i < m; ++i)
        {
                cin>>arr2[i];
        }
        cout<<kth(arr1,arr2,arr1+n,arr2+m,k-1)<<endl;

}
}
