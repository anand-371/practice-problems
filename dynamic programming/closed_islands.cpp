/*Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:



Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/
class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int rsize,csize;
    void dfs(int x , int y , vector<vector<int>>&A)
    {
        if(x < 0 || x >= rsize || y < 0 || y >= csize || A[x][y] == 1)
            return;
        A[x][y] = 1;
        for(int i = 0 ; i < 4 ; i++)
            dfs(x + dx[i],y +dy[i],A);
    }
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        rsize = grid.size();
        csize = grid[0].size();
        int cc = 0;
        for(int i = 0 ; i < rsize ; i++)
            for(int j = 0 ; j < csize ; j++)
                if(i == 0 || j == 0 || i == rsize-1 || j == csize-1)
                    if(grid[i][j] == 0)
                        dfs(i,j,grid);
       
        for(int i = 0 ; i < rsize ; i++)
            for(int j = 0 ; j < csize ; j++)
                if(grid[i][j]==0)
                {
                    dfs(i,j,grid) ;
                    cc++;
                }
        return cc;
    }
};
