/*
Decode String
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
*/

class Solution {
public:
    string decodeString(string A) {
        stack<char> s;      //for storing char other than numbers
        vector<int> no;     //for storing numbers
        
        for(int i=0; i<A.length(); i++)
        {
            if(isdigit(A[i]))
            {
                int d = 0;
                while(isdigit(A[i]))
                {
                    d = d*10 + (A[i] - '0');
                    i++;
                }
                cout<<d;
                no.push_back(d);
                
            }
            
            if(A[i] == ']')
            {
                string str = "";
                while(s.top() != '[')
                {
                    str += s.top();
                    s.pop();
                }
                reverse(str.begin(),str.end());
                s.pop();
                
                int d = no[no.size()-1];
                cout<<d;
                no.pop_back();
                for(int i=0; i<d; i++)      //push string k no of times in the stack
                {
                    for(int j=0; j<str.length(); j++)
                    {
                        s.push(str[j]);
                    }
                }
            }
            else
                s.push(A[i]);
        }
        
        
        string ans = "";
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
