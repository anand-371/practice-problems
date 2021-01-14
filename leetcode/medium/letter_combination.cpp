/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9']
*/
class Solution {
public:
    
vector<string>combi(vector<string>&result,int n,string digits){
    std::map<char, string> m;
    string table[10]= { "0",   "1",   "abc",  "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz" };
    queue<string>q;
    q.push("");
    while(!q.empty()){
        string s=q.front();
        q.pop();

        if (s.length()==n)
        {
            result.push_back(s);
        }else{
            cout<<s.length()<<endl;
            cout<<digits[s.length()]-'0'<<endl;
            for(auto x : table[digits[s.length()]-'0']){
                q.push(s+x);
            }
        }

    }
    return result;
}

vector<string> letterCombinations(string digits) {
    int n=digits.length();
    std::vector<string> result ;
    if(digits.size()==0){
        return result;
    }
    combi(result,n,digits);
    return result;
        
    }
};
