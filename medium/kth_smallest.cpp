/*
Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 
#include <limits.h>
#include <algorithm>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int pivot(int arr[],int l,int r){
    int x=arr[r];
    int i=l;
    for (int j = l; j < r; ++j)
    {
        if (arr[j]<=x)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;

}
int kth(int arr[],int l,int r,int k){
    if (k>0 && k<=r-l+1)
    {
        int pos=pivot(arr,l,r);
        if (pos-l==k-1)
        {
            return arr[pos];
        }else if (pos-l>k-1)
        {
            return kth(arr,l,pos-1,k);
        }else{
            return kth(arr,pos+1,r,k-pos+l-1);
        }
    }
}
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
        cout<<kth(arr,0,n-1,k)<<endl;
    }
    return 0;
}
