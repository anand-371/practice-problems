/*
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. 
The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'M'
denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. 
The third line contains an integer 'N' denoting the cents.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 
#include <limits.h>
#include <algorithm>

int count( int S[], int m, int n ) 
{  
    int table[n+1]; 
    memset(table, 0, sizeof(table)); 
    table[0] = 1; 
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    return table[n]; 
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
        cin>>m;
        cout<<count(arr,n,m)<<endl;


    }
}


