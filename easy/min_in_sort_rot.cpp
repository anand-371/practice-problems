/*
Minimum element in a sorted and rotated array
A sorted array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Expected Time Complexity: O(Log n)

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. 
The first line of each test case consists of an integer N, where N is the size of array.
The second line of each test case contains N space separated integers denoting array elements.

Output:
Corresponding to each test case, in a new line, print the minimum element in the array.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 
#include <limits.h>
#include <algorithm>
int binary(int arr[],int n){
    int start=0;
    int end=n-1;
    int mid;
    while(start<=end){
        mid=(start+end)/2;
        if ((mid==start || arr[mid]<arr[mid-1]) &&(mid==end || arr[mid]<arr[mid+1]))
        {
            return arr[mid];
        }else if(arr[mid]<arr[end]){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
}


int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        cout<<binary(arr,n)<<endl;

    }
}

