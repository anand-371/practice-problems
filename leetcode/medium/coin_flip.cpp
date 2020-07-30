We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
/*

class Solution {
public:
    void fliprow(vector<vector<int>>& A,int row,int n){
    for (int i = 0; i < n; ++i)
    {
        A[row][i]=1-A[row][i];
    }
}
void flipcol(vector<vector<int>>& A,int col,int m){
    for (int i = 0; i < m; ++i)
    {
        A[i][col]=1-A[i][col];
    }
}
    int matrixScore(vector<vector<int>>& A) {
        int r=A.size();
        int c=A[0].size();
        std::vector<int> colCount(c,0);
        for (int i = 0; i < r; ++i)
        {
            if (A[i][0]==0)
            {
                fliprow(A,i,c);
            }
            for (int j = 0; j < c; ++j)
            {
                if (A[i][j]==1)
                {
                    colCount[j]++;
                }
            }
        }
            for (int j = 0; j < c; ++j)
            {
                    if (colCount[j]<=r/2)
                    {
                        flipcol(A,j,r);
                    }
            }
            int ans=0;
            for(auto v: A) {
            int result = 0, p = 0;
            for(int i=v.size()-1; i>=0; i--) {
                result+=v[i]*pow(2,p);
                p++;
            }
            ans += result;
        }
        
                return ans;
    }
};
*/
