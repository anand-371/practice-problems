/*
Number of Moves to Capture the King
You are given a two-dimensional integer matrix board containing 0s, 1s and 2s representing some n x n chessboard. Each 0 represents an empty cell, 1 represents the knight and 2 represents the king. There is at least one knight but exactly one king.

Given that the king stays still, return the minimum number of moves it would take for some knight to land on the king. If there's no solution, return -1. A knight can't land on another knight.

Constraints

2 ≤ n ≤ 500 where n is the number of rows and columns in board
1 ≤ t < n * n where t is the number of knights
k = 1 where k is the number of kings.
Example 1
Input
board = [
    [1, 0, 0, 0, 0],
    [0, 0, 0, 0, 0],
    [0, 0, 0, 0, 2],
    [1, 0, 0, 0, 0],
    [0, 0, 0, 0, 0]
]
Output
2
Explanation
The knight on top left corner can jump twice to land on the king.

Example 2
Input
board = [
    [1, 2],
    [1, 1]
]
Output
-1
*/
bool is_valid(int i,int j,int n,int m){
    return (i>=0 && j>=0 && i<n && j<m);
}

int solve(vector<vector<int>>& board) {
    int n=board.size();
    int m=board[0].size();
    queue<pair<int,int>>q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    int flag=true;
    for (int i = 0; i < n; ++i)
    {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j]==2)
                {
                    q.push(make_pair(i,j));
                    dist[i][j]=0;
                    flag=false;
                    break;
                }
            }
            if (flag==false)
            {
                break;
            }
    }
    vector<int> xdir{1, 2, -1, 2, -1, -2, 1, -2};
    vector<int> ydir{2, 1, 2, -1, -2, -1, -2, 1};
    while(!q.empty()){
        int size=q.size();
        while(size--){
            pair<int,int>temp=q.front();
            q.pop();
            int i=temp.first;
            int j=temp.second;
            for (int k = 0; k <8; ++k)
            {
                    int x=i+xdir[k];
                    int y=j+ydir[k];
                    if (is_valid(x,y,n,m) && board[x][y]!=2 && dist[x][y]>dist[i][j]+1)
                    {
                        if (board[x][y]==1)
                        {
                            return dist[i][j]+1;
                        }
                        dist[x][y]=dist[i][j]+1;
                        q.push({x,y});
                    }
            }

        }
    }
    return -1;
}
