/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/
class Solution {
public:
int search(string s,int left,int right){
    if (left>right || s.length()<right)
    {
        return 0;
    }
    while(left>=0 && right<s.length() && s[left]==s[right]){
        left--;
        right++;
    }
    return (right-left-1);
}

string longestPalindrome(string s) {
    int max_len;
    int start=0;
    int end=0;
    for (int i = 0; i < s.length(); ++i)
    {
        int len1=search(s,i,i);
        int len2=search(s,i,i+1);
        max_len=std::max(len1,len2);

        if (max_len>end-start)
        {
            start=i-((max_len-1)/2);
            end=i+(max_len/2);
        }
    }
    string temp="";
    for (int i =start; i <=end; ++i)
    {
        temp+=s[i];
    }
    return temp;
    }
};
