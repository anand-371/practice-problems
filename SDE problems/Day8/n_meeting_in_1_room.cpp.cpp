/*
N meetings in one room
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room?

Input:
The first line of input consists number of the test cases. The description of T test cases 
is as follows:
The first line consists of the size of the array, second line has the array containing 
the starting time of all the meetings each separated by a space, i.e., S [ i ]. 
And the third line has the array containing the finishing time of all the meetings each 
separated by a space, i.e., F [ i ].

Output:
In each separate line print the order in which the meetings take place separated by a space.

Constraints:
1 ≤ T ≤ 70
1 ≤ N ≤ 100
1 ≤ S[ i ], F[ i ] ≤ 100000

Example:
Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:
1 2 4 5
6 7 1

Explanation:
Testcase 1: Four meetings can held with given start and end timings.
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
        for (int i = 0; i < tup.size(); ++i)
        {
            //cout<<tup[i][0]<<" ";
            if (tup[i][1]>prev_end)
            {   cout<<tup[i][0]<<" ";
                prev_end=tup[i][2];
            }
        }
        cout<<endl;

    }
}
