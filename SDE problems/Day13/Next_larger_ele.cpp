/*
Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array
in order of their appearance in the array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of 
two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive 
integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long int t,n,m,k;
    cin>>t;
    while(t--){
        cin>>n;
        long long int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        stack<long long int>st;
        long long int i=0;
        long long int count=0;
        std::vector<long long int> result(n,0);
        for (int i = n-1; i>=0; i--)
        {
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if (st.empty())
            {
                result[i]=-1;
            }else{
                result[i]=st.top();
            }
            st.push(arr[i]);
        }
        for (int i = 0; i < n; ++i)
        {
                cout<<result[i]<<" ";
        }
        cout<<endl;
        }

}

