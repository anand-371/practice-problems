/*
Smallest subarray with sum greater than x
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Examples:
A[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two space separated integers N and x. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print the required ouput.

Constraints:
1<=T<=100
1<=N,x<=1000
1<=A[]<=1000

Example:
Input:
2
6 51
1 4 45 6 0 19
5 9
1 10 5 2 7
Output:
3
1
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 
#include <limits.h>
#include <algorithm>
int sum_of(int arr[], int l,int r,int x){
    int sum=0;
    for (int i = l; i < r; ++i)
    {
        sum+=arr[i];
    }
    if (sum>x)
    {
        return sum;
    }else{
        return -1;
    }
}
int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        int start=0;
        int min_length=n+1;
        int end=0;
        int curr_sum=0;
        while(end<n){
            while(curr_sum<=x && end<n){
                curr_sum+=arr[end];
                end++;
            }
           
            while(curr_sum>x && start<n){
                 if (end-start<min_length)
                 {
                min_length=end-start;
                    }
                curr_sum-=arr[start];
                start++;
            }
        }
        cout<<min_length<<endl;

    }
    return 0;
}

