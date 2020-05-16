/*
Given an array of N positive integers  a1, a2 ............ an. The value of each contiguous subarray of given array 
is the maximum element present in that subarray. The task is to return the number of subarrays having value strictly 
greater than K.

Input:
The first line of the input contains 'T' denoting the total number of testcases. Then follows the description of 
testcases. The first line of each testcase contains two space separated positive integers N and K denoting the size
 of array and the value of K. The second line contains N space separated positive integers denoting the elements of
  array.
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<math.h>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)    cin >> arr[i];
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                count++;
            }
            else{
                sum+=(count*(count+1)/2);
                count=0;
            }
        }
        sum+=(count*(count+1)/2);
        int total=(n*(n+1)/2);
        cout << total-sum << endl;
    }
    
return 0;}

