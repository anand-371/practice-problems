/*
Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person,
assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. First line is N number of activities then second
line contains N numbers which are starting time of activies.Third line contains N finishing time of activities.

Output:
For each test case, output a single number denoting maximum activites which can be performed in new line.

Constraints:
1<=T<=50
1<=N<=1000
1<=A[i]<=100

Example:
Input:
2
6
1 3 2 5 8 5
2 4 6 7 9 9
4
1 3 2 5
2 4 3 6

Output:
4
4

Explanation:
Test Case 1: The following activities can be performed (in the same order):
(1, 2)
(3, 4)
(5, 7)
(8, 9)
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        std::vector<int> start(n,0);
        std::vector<int> end(n,0);
        std::vector<vector<int>> tup;
        for (int i = 0; i < n; ++i)
        {
            cin>>start[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>end[i];
        }
        for (int i = 0; i < n; ++i)
        {   std::vector<int> temp;
            temp.push_back(i+1);
            temp.push_back(start[i]);
            temp.push_back(end[i]);
            tup.push_back(temp);
        }
        sort(tup.begin(),tup.end(),[](vector<int>&a,vector<int>&b){
            if (a[2]==b[2])
            {
                return a[1]<b[1];
            }else{
                return a[2]<b[2];
            }
        });
        int prev_end=0;
        int prev_start=0;
        int count=0;
        for (int i = 0; i < tup.size(); ++i)
        {
            //cout<<tup[i][0]<<" ";
            if (tup[i][1]>=prev_end)
            {   count++;
                prev_end=tup[i][2];
            }
        }
        cout<<count<<endl;

    }
}
