/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/
class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
         if(s.length()<10)return {};
        unordered_map<string,int>u;
        int i;
        for(i=0;i<=s.length()-10;i++)
        {
            u[s.substr(i,10)]++;
        }
        vector<string>ans;
        for(auto it:u)
        {
            if(it.second>1)ans.push_back(it.first);
        }
        return ans;
    }
};
