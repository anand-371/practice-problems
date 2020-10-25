/*
Find Nth root of M 
You are given 2 numbers (N , M); the task is to find N√M (Nth root of M).

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two space separated integers N and M.

Output:
For each test case, in a new line, print an integer denoting Nth root of M if the root is an integer else print -1.

Constraints:
1 <= T <= 200
2 <= N <= 20
1 <= M <= 109+5

Example:
Input:
2
2 9
3 9
Output:
3
-1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        float r=pow(b,(1.0/a));
        if((int)r==r)
            cout<<r<<endl;
        else
            cout<<-1<<endl;
    }
}

