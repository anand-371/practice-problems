/*
Given a string s, find out the count of all contiguous substrings 
whose starting and ending are same character.
Note: string contains lowercase English alphabets only.
The first line of each test case contains an integer T denoting the number of test cases. 
Then T test cases follows. The first line of each test case contains a number N denoting the length of the string (S). 
Then the next line contains the string S.
Input  : S = "abcab"
Output : 7
There are 15 substrings of "abcab"
a, ab, abc, abca, abcab, b, bc, bca
bcab, c, ca, cab, a, ab, b
Out of the above substrings, there 
are 7 substrings : a, abca, b, bcab, 
c, a and b.

Input  : S = "aba"
Output : 4
The substrings are a, b, a and aba
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int t; 
    cin>>t;
    while(t--)
    {
        unsigned int n,res=0; 
        cin>>n;
        string s; 
        cin>>s;
        int arr[25];
        for(int i=0;i<=25;i++)arr[i]=0;
        
        for(int i=0;i<n;i++)
        {
            arr[s[i]-97]++;
        }
        for(int i=0;i<=25;i++)
        {
            int a=arr[i];
            res+=(a*(a+1))/2;
        }
        cout<<res<<endl;
    }
    return 0;
}