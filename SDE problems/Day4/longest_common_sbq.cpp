/*
Longest consecutive subsequence
Given an array arr[] of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Input:
The first line of input contains T, number of test cases. First line of line each test case contains a single integer N.
Next line contains N integer array.

Output:
Print the output of each test case in a seprate line.

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= a[i] <= 105

Example:
Input:
2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:
6
4

Explanation:
Testcase 1:  The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

Testcase2: 1, 2, 3, 4 is the longest consecutive subsequence.
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
        std::map<int, int> m;
        for (int i = 0; i < n; ++i)
        {
            m[v[i]]++;
        }
        int max=0;
        for (int i = 0; i < n; ++i)
        {   int count=0;
            if (m.find(v[i]-1)==m.end())    
            {   
                int j=v[i];
                while(m.find(j)!=m.end()){
                    count++;
                    j++;
                }
                max=std::max(max,count);
            }
        }
        cout<<max<<endl;
    } 
}
