/*
Sum of Lengths of Non-Overlapping SubArrays 
Given an array of N elements, you are required to find the maximum sum of lengths of all non-overlapping subarrays with K as the maximum element in the subarray.
.
Input:
First line of the input contains an integer T, denoting the number of the total test cases. Then T test case follows. First line of the test case contains an integer N, denoting the number of elements in the array. Then next line contains N space separated integers denoting the elements of the array. The last line of each test case contains an integer K.

Output:
For each test case ouptut a single line denoting the sum of the length of all such subarrays.
Input:
3
9 
2 1 4 9 2 3 8 3 4
4
7
1 2 3 2 3 4 1
4
10
4 5 7 1 2 9 8 4 3 1
4
Output:
5
7
4
Explanation:
Test Case 1:
{2, 1, 4} => Length = 3
{3, 4} => Length = 2
So, 3 + 2 = 5 is the answer

Test Case 2: {1, 2, 3, 2, 3, 4, 1} => Length = 7

Test Case 3:
{4} => Length = 1
{4, 3, 1} => Length = 3
So, 1 + 3 = 4 is the answer.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 
#include <limits.h>
#include <algorithm>
int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        cin>>k;
        std::vector<int> index;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i]==k)
            {
                index.push_back(i);
            }
        }
        int count=0;
        bool flag=true;
        for (int i = 0; i <index.size(); ++i)
        {   flag=true;
            for (int j = index[i]+1; j < n; ++j)
            {
                if (arr[j]>k)
                {   flag=false;
                    break;
                }else{
                    count++;
                }
            }
        }
        
        for (int i = 0; i <index.size(); ++i)
        {   flag=true;
            for (int j = index[i]-1; j >= 0; j--)
            {
                if (arr[j]>k)
                {   flag=false;
                    break;
                }else{
                    count++;
                }
            }
        }

        cout<<count+index.size()<<endl;

    }
    return 0;
}
