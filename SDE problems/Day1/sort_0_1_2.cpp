/*
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output: 
For each testcase, print the sorted array.
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
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        int count0=0;
        int count1=0;
        int count2=0;
        for (int i = 0; i <n ; ++i)
        {
            if (arr[i]==0)
            {
                count0++;
            }
            if (arr[i]==1)
            {
                count1++;
            }
            if (arr[i]==2)
            {
                count2++;
            }
        }
        int i=0;
        while(count0--){
            cout<<"0 ";
        }
        while(count1--){
            cout<<"1 ";
        }
        while(count2--){
            cout<<"2 ";
        }
    }
       
}

