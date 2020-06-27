/*
You are given an array of integers. You need to print the total count of sub-arrays having their sum equal to 0

Input:
First line of the input contains an integer T denoting the number of test cases. Each test case consists of two lines. First line of each test case contains an Integer N denoting the size of the array, and the second line contains N space separated integers.

Output:
For each test case, in a new line, print the total number of subarrays whose sum is equal to 0.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

#include<iostream>
#include<unordered_map>
using namespace std;
int main()
 {
int t;
cin >> t;
while(t--)
{
    long int n;
    cin >> n;
    long long int ar[n];
    for(int i=0;i<n;i++)
    cin >> ar[i];
    unordered_map<int,int> map;
    
    int ans = 0;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=ar[i];
        if(sum==0)
        ans++;
        
        if(map.find(sum)!=map.end())
        {
            ans+=map[sum];
        }
        
        map[sum]++;
    }
    cout << ans << endl;
    
}
}
