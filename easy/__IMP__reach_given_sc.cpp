
/*
Reach a given score
Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find the number of distinct combinations to reach the given score.
Input:
The first line of input contains an integer T denoting the number of test cases. T test cases follow. The first line of each test case is n.

Output:
For each testcase, in a new line, print the number of ways/combinations to reach the given score.

Note: The tricky part is that , question has asked for combinations not permutations
If only permutations were asked , we could have simply done dp[i]=dp[i-3]+dp[i-5]+dp[i-10] , as it does not care about the duplicate sets .
Now to avoid that,
1) first mark all values which can be made by moving 3 .
eg if n=8 . all values that can be made using only 3 coins are multiple of 3 .
Technically we write it as dp[i]=d[i]+dp[i-3];
2)Now moves using 3 are done , mark all moves by moving 5 , This gives us all combinations that can be made using only 3 and 5
Technically we write it as dp[i]=dp[i]+dp[i-5]
3)Now moves using 3 and 5 are done , mark all moves by moving 10 , This gives us all combinations that can be made using 3 , 5 and 10(note that we would never come across duplicated in such a case)
Technically we write it as dp[i]=dp[i]+dp[i-10]

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 

int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {   cin>>n;
        int dp[n+1]={0};
        dp[0]=1;
        for (int i = 3; i <=n; ++i)
        {
            dp[i]+=dp[i-3];
        }
        for (int i = 5; i <=n; ++i)
        {
            dp[i]+=dp[i-5];
        }
        for (int i = 10; i <=n; ++i)
        {
            dp[i]+=dp[i-10];
        }
        cout<<dp[n]<<endl;
    }
       
}

