/*
Steps by Knight
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the 
size of the square chessboard. The next line contains the X-Y coordinates of the knight. The next line contains the X-Y coordinates of the target. 

Output:
Print the minimum steps the Knight will take to reach the target position.

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (knightPos),
the target position of Knight (targetPos) and the size of the chess board (N) as inputs and returns the minimum number of steps required by the knight to reach from
its current position to the given target position.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= knight_pos(X, Y), targer_pos(X, Y) <= N

Example:
Input:
2
6
4 5
1 1
20
5 7
15 20

Output:
3
9

Explanation:
Test Case 1:

Knight takes 3 step to reach from (4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.
*/

#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int *, int *, int);

// Driver code to test above methods
int main() {
    // size of square board
    int t;
    cin >> t;
    while (t--) {
        int N;
        int a, b, c, d;
        cin >> N;
        cin >> a >> b;
        cin >> c >> d;
        int knightPos[] = {a, b};
        int targetPos[] = {c, d};
        cout << minStepToReachTarget(knightPos, targetPos, N) << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// KnightPos : knight position coordinates
// targetPos : target position coordinated
// N : square matrix size
bool check(int i,int j,int N){
    if (i>0 && i<=N && j>0 && j<=N)
    {
        return true;
    }
    return false;
}
int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
    bool visited[N+1][N+1];
    for (int i = 0; i <=N; ++i)
    {
        for (int j = 0; j <=N; ++j)
        {
                visited[i][j]=false;
        }
    }
    queue<pair<int,int>>q;
    q.push(make_pair(knightPos[0],knightPos[1]));
    int size=0;
    int distance=0;
    while(!q.empty()){
        size=q.size();
        while(size--){
            pair<int,int>temp;
            temp=q.front();
            q.pop();
            if(temp.first==targetPos[0] && temp.second==targetPos[1]){
                return distance;
            }
            if (check(temp.first-2,temp.second+1,N) && visited[temp.first-2][temp.second+1]==false)
            {   visited[temp.first-2][temp.second+1]=true;
                q.push(make_pair(temp.first-2,temp.second+1));
            }
            if (check(temp.first-2,temp.second-1,N) && visited[temp.first-2][temp.second-1]==false)
            {   visited[temp.first-2][temp.second-1]=true;
                q.push(make_pair(temp.first-2,temp.second-1));
            }
            if (check(temp.first-1,temp.second-2,N)&&visited[temp.first-1][temp.second-2]==false)
            {   visited[temp.first-1][temp.second-2]=true;
                q.push(make_pair(temp.first-1,temp.second-2));
            }
            if (check(temp.first-1,temp.second+2,N)&&visited[temp.first-1][temp.second+2]==false)
            {   visited[temp.first-1][temp.second+2]=true;
                q.push(make_pair(temp.first-1,temp.second+2));
            }
            if (check(temp.first+1,temp.second+2,N)&& visited[temp.first+1][temp.second+2]==false)
            {   visited[temp.first+1][temp.second+2]=true;
                q.push(make_pair(temp.first+1,temp.second+2));
            }
            if (check(temp.first+1,temp.second-2,N)&& visited[temp.first+1][temp.second-2]==false)
            {   visited[temp.first+1][temp.second-2]=true;
                q.push(make_pair(temp.first+1,temp.second-2));
            }
            if (check(temp.first+2,temp.second+1,N) && visited[temp.first+2][temp.second+1]==false)
            {   visited[temp.first+2][temp.second+1]=true;
                q.push(make_pair(temp.first+2,temp.second+1));
            }
            if (check(temp.first+2,temp.second-1,N)&&visited[temp.first+2][temp.second-1]==false)
            {   visited[temp.first+2][temp.second-1]=true;
                q.push(make_pair(temp.first+2,temp.second-1));
            }
        }
        distance++;
    }
    return -1;
}
