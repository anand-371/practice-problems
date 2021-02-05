/*
Find whether path exist
Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
 

Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0 
3 0 0 0 3 
3 3 3 3 3 
0 2 3 0 0 
3 0 0 1 3 
There is no path to reach at (3,1) i,e at 
destination from (4,3) i,e source.
Example 2:

Input: grid = {{1,3},{3,2}}
Output: 1
Explanation: The grid is-
1 3
3 2
There is a path from (0,0) i,e source to (1,1) 
i,e destination.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function is_Possible() which takes the grid as input parameter and returns boolean value true if there is a path otherwise returns false.
 

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)
*/

bool is_safe(int i,int j,int n,int m){
    if (i>=n || j>=m || i<0 || j<0)
    {
        return false;
    }
    return true;
}

bool dfs_util(vector<vector<int>>& grid,vector<vector<int>>&visited,int i,int j,int ex,int ey){
    if (i==ex && y==ey)
    {
        return true;
    }
    if (!is_safe(i,j,grid.size(),grid[0].size()) || visited[i][j]==1)
    {
        return false;
    }
    visited[i][j]=1;
    return dfs_util(grid,visited,i+1,j,ex,ey)|| dfs_util(grid,visited,i-1,j,ex,ey)||dfs_util(grid,visited,i,j+1,ex,ey)||dfs_util(grid,visited,i,j-1,ex,ey);

}


bool is_Possible(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>visited(n,vector<int>v(m,0));
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    for (int i = 0; i < n; ++i)
    {
            for (int j = 0; j < m; ++j)
            {
                    if (grid[i][j]==1)
                    {
                        start_x=i;
                        start_y=j;
                    }else if (grid[i][j]==2)
                    {
                        end_x=i;
                        end_y=j;
                    }
            }
    }
    return dfs_util(grid,visited,start_x,start_y,end_x,end_y);

    }
