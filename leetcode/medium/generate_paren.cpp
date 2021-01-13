/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/
class Solution {
public:
    
void backtrack(vector<string>&A,string curr,int open,int close,int max){
    if (curr.length()==max*2)
    {
        A.push_back(curr);
        return;
    }
    if (open<max)
    {
        backtrack(A,curr+"(",open+1,close,max);
    }
    if (close<open)
    {
        backtrack(A,curr+")",open,close+1,max);
    }
}

vector<string> generateParenthesis(int n) {
        std::vector<string> A;
        backtrack(A,"",0,0,n);
        return A;
    }

};
