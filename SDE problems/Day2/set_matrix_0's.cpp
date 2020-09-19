/*
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    std::vector<pair<int,int>> v;
        pair<int,int>pr;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j]==0)
                {
                    v.push_back(make_pair(i,j));
                }
            }
        }
        for (auto x:v)
        {   int n=matrix[0].size();
            int m=matrix.size();
            for(int i=0;i<n;i++){
                matrix[x.first][i]=0;
            }
            for (int i = 0; i < m; ++i)
            {
                matrix[i][x.second]=0;
            }
        }
    }
};