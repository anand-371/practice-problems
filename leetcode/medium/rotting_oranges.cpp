/*
Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

class Solution {
public:
bool is_safe(int i,int j,int n,int m){
    if (i>=n || j>=m ||i<0 || j<0)
    {
        return false;
    }
    return true;
}

int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        std::vector<vector<int>> visted(grid.size(),std::vector<int>(grid[0].size(),0));
        int fresh=0;
        queue<pair<int,int>>q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                    if (grid[i][j]==1)
                    {
                        fresh++;
                    }
                     if (grid[i][j]==2)
                    {
                        q.push(make_pair(i,j));
                    }
            }
        }
        int ans=-1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
            pair<int,int>temp=q.front();
            q.pop();
                int i=temp.first;
                int j=temp.second;
            if (is_safe(i+1,j,n,m) && grid[i+1][j]==1)
            {
                grid[i+1][j]=2;
                q.push(make_pair(i+1,j));
                fresh--;
            }
            if (is_safe(i-1,j,n,m) && grid[i-1][j]==1)
            {
                grid[i-1][j]=2;
                q.push(make_pair(i-1,j));
                fresh--;
            }
            if (is_safe(i,j+1,n,m) && grid[i][j+1]==1)
            {
                grid[i][j+1]=2;
                q.push(make_pair(i,j+1));
                fresh--;
            }
            if (is_safe(i,j-1,n,m) && grid[i][j-1]==1)
            {
                grid[i][j-1]=2;
                q.push(make_pair(i,j-1));
                fresh--;
            }
        }
            ans++;
        }
        if (fresh>0)
        {
            return -1;
        }
        if (ans==-1)
        {
            return 0;
        }
        return ans;

    }
};
