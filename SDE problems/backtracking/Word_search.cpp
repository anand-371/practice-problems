/*
Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 
*/

class Solution {
public:
bool back_track(vector<vector<char>>& board,string word,int i,int j,int wordpos){
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size())
    {
        return false;
    }
    if (board[i][j]!=word[wordpos])
    {
        return false;
    }
    if(wordpos==word.length()-1){
        return true;
    }
    char curr=board[i][j];
    board[i][j]='.';
    bool res=back_track(board,word,i-1,j,wordpos+1)||back_track(board,word,i+1,j,wordpos+1)||back_track(board,word,i,j-1,wordpos+1)||back_track(board,word,i,j+1,wordpos+1);
    board[i][j]=curr;
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for (int i = 0; i < n; ++i)
        {
                for (int j = 0; j < m; ++j)
                {
                        if (back_track(board,word,i,j,0)==true)
                        {
                            return true;
                        }
                }
        }
        return false;
    }
};
