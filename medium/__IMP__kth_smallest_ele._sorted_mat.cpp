/*
Kth element in Matrix
Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.


Your Task:
You don't need to read input or print anything. Complete the function kthsmallest() which takes the mat, N and K as input parameters and returns the kth smallest element in the matrix.
 

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)
*/


bool compare(pair<int,pair<int,int>> &d1,pair<int,pair<int,int>> &d2){
    return (d1.first>d2.first);
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, decltype(&compare)> pq(compare);
    for (int i = 0; i < n; ++i)
    {
            pq.push({mat[0][i],{0,i}});
    }
    int ans=0;
    while(k--){
        pair<int,pair<int,int>> temp=pq.top();
        ans=temp.first;
        pq.pop();
        int col=temp.second.second;
        int row=temp.second.first;
        if (row!=n-1)
        {
            row++;
            pq.push({mat[row][col],{row,col}});
        }
    }
    return ans;
}
