/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.

Constraints:
1 ≤ T ≤ 110
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107

Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,t;
    cin>>t;
    while(t--)
    { 
        cin>>n;
        std::vector<int> v(n,0);
        for (int i = 0; i < n; ++i)
        {
            cin>>v[i];
        }
        int max_till_now=0;
        int max=0;
        for (int i = 0; i < n; ++i)
        {
            if (max<0)
            {
                max=0;
            }
            max+=v[i];
            max_till_now=std::max(max,max_till_now)
        }
        cout<<max_till_now<<endl;
    }

       
}

