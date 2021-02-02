/*
Minimum Swaps to Sort
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i,e in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes grid as input parameter and returns the total number of islands.
 

Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 

Constraints:
1 <= n, m <= 500
*/

class Solution {
public:
    void dfs_util(vector<vector<char>>& grid,int i,int j){
    if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0')
    {
        return ;
    }
        grid[i][j]='0';
        dfs_util(grid,i+1,j);
        dfs_util(grid,i-1,j);
        dfs_util(grid,i,j+1);
        dfs_util(grid,i,j-1);
        dfs_util(grid,i+1,j+1);
        dfs_util(grid,i+1,j-1);
        dfs_util(grid,i-1,j+1);
        dfs_util(grid,i-1,j-1);
        return;
}

int numIslands(vector<vector<char>>& grid) {
        int components=0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j]=='1')
                {   dfs_util(grid,i,j);
                    components++;
                }
            }
        }
        return components;
    }
};
