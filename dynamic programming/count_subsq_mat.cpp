/*
Count Square Submatrices with All Ones

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int arr[rows][cols];
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                    arr[i][j]=0;
            }
        }
        for (int i = 0; i < rows; ++i)
        {
            arr[i][0]=matrix[i][0];
        }
        for (int i = 0; i < cols; ++i)
        {
            arr[0][i]=matrix[0][i];
        }
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {       
                if (matrix[i][j]==1)
                {
                arr[i][j]=min(arr[i-1][j],arr[i-1][j-1],arr[i][j-1])+1;
                }else{
                    arr[i][j]=0;
                    
            }
                }
        }
        int sum=0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                    sum+=arr[i][j];
            }
        }
        return sum;
    }
     int min(int a,int b,int c){
        return std::min({a, b, c});
    }
};
