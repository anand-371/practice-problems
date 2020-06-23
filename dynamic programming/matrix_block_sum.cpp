/*
1314. Matrix Block Sum
Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, K <= 100
1 <= mat[i][j] <= 100
*/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows=mat.size();
        int cols=mat[0].size();
        int prefix[rows+1][cols+1];
        for (int i = 0; i < rows+1; ++i)
        {
            for (int j = 0; j < cols+1; ++j)
            {
                    prefix[i][j]=0;
            }
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                prefix[i+1][j+1]=mat[i][j]+ prefix[i+1][j] +prefix[i][j+1]-prefix[i][j];
            }
        }
        int answer[rows][cols];
        for (int i = 0; i < rows; ++i)
        {
                for (int j = 0; j < cols; ++j)
                {
                        answer[i][j]=0;
                }
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                    int r1=max(0,i-k);
                    int c1=max(0,j-k);
                    int r2=min(rows-1,i+k);
                    int c2=min(cols-1,j+k);
                    answer[i][j]=prefix[r2+1][c2+1]-prefix[r2+1][c1]-prefix[r1][c2+1]+ prefix[r1][c1];

            }
        }
        //algorithm ends here
        //converts the 2D array to vector
        vector<vector<int>> result;

        for (int i = 0; i < rows; ++i)
        {   std::vector<int> temp;
            for (int j = 0; j < cols; ++j)
            {       
                    temp.push_back(answer[i][j]);
            }
            result.push_back(temp);
        }
        return result;
    }
int max(int a,int b){
    if (a>b)
    {
        return a;
    }else{
        return b;
    }
}
int min(int a,int b){
    if (a>b)
    {
        return b;
    }else{
        return a;
    }
}
};
