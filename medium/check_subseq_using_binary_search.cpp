/*
Subsequence Match Target

Given a list of string words and a string s, return the number of strings in words that are subsequences of s.

Constraints

n ≤ 10,000 where n is the length of words
m ≤ 100,000 where m is the length of s
Example 1
Input
words = ["ac", "ad", "b"]
s = "abc"
Output
2
Explanation
"ac" and "b" are subsequences of "abc".
*/
bool check(string s,vector<vector<int>>&record) {
        int index = -1;
        for(int i = 0; i < s.size(); i++) {
            auto iter = upper_bound(record[s[i]-'a'].begin(), record[s[i]-'a'].end(), index);
            if(iter == record[s[i]-'a'].end()) return false;
            index = *iter;
        }
        return true;
    }
int solve(vector<string>& words, string s) {
    int count=0;
    vector<vector<int>> record(26);
    for(int i = 0; i < s.size(); i++) {
            record[s[i]-'a'].push_back(i);
        }
    for (int i = 0; i <words.size(); ++i)
    {
        if (check(words[i],record))
        {
            count++;
        }
    }
    return count;
}
