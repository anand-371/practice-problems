/*
Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
Structure is like below:
|  |
|_|
We can trap 2 units of water in the middle gap.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains an integer N denoting the size of the array, followed by N space separated numbers to be stored in array.

Output:
Output the total unit of water trapped in between the blocks.

Constraints:
1 <= T <= 100
3 <= N <= 107
0 <= Ai <= 108

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Testcase 1: Water trapped by block of height 4 is 3 units, block of height 0 is 7 units. So, total unit of water trapped is 10 units.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
                cin>>arr[i];
        }
        int left[n];
        int right[n];
        left[0]=arr[0];
        for (int i = 1; i < n; ++i)
        {
            left[i]=std::max(left[i-1],arr[i]);
        }
        right[n-1]=arr[n-1];
        for (int i = n-2; i >=0 ; i--)
        {
            right[i]=std::max(right[i+1],arr[i]);
        }
        int final=0;
        for (int i =0; i < n; ++i)
        {
           final+=(std::min(left[i],right[i])-arr[i]);
        }
        cout<<final<<endl;
    }
}
