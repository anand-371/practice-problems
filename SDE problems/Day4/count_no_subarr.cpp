/*
Count the number of subarrays having a given XOR
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m

An Efficient Solution solves the above problem in O(n) time. Let us call the XOR of all elements in the range [i+1, j] as A,
in the range [0, i] as B, and in the range [0, j] as C. If we do XOR of B with C, the overlapping elements in [0, i] from B and C zero
out and we get XOR of all elements in the range [i+1, j], i.e. A. Since A = B XOR C, we have B = A XOR C. Now, if we know the value of
C and we take the value of A as m, we get the count of A as the count of all B satisfying this relation. Essentially, we get the count
of all subarrays having XOR-sum m for each C. As we take sum of this count over all C, we get our answer.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,t,m1;
    cin>>t;
    while(t--)
    {   
        cin>>n>>m1;
        std::vector<int> v(n,0);
        for (int i = 0; i < n; ++i)
        {
                cin>>v[i];
        }
        std::map<int, int> m;
        std::vector<int> prefix(n,0);
        prefix[0]=v[0];
        for (int i = 1; i < n; ++i)
        {
            prefix[i]=prefix[i-1]^v[i];
        }
        int res=0;
        for (int i = 0; i <n ; ++i)
        {
            int temp=m1^prefix[i];
            res+=m[temp];
            if (prefix[i]==m1)
            {
                res++;
            }
            m[temp]++;
        }
        cout<<res<<endl;
    } 
}
