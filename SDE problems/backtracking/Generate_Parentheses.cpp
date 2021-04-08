/*
 Generate Parentheses
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
    
void back_track(vector<string>&store,int open,int close,string temp,int max){
    if (temp.size()==max*2)
    {
        store.push_back(temp);
        return;
    }
    if (open<max)
    {
        back_track(store,open+1,close,temp+'(',max);
    }
    if (close<open)
    {
        back_track(store,open,close+1,temp+')',max);
    }
    return;
}
vector<string> generateParenthesis(int n) {
        vector<string>store;
        back_track(store,0,0,"",n);
        return store;
    }


};
