/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0){
        return "";
    }
    int min_len=INT_MAX;
    int index=0;
    for (int i = 0; i < strs.size(); ++i)
    {
        if (min_len<strs[i].length())
        {
            min_len=strs[i].length();
            index=i;
        }
    }
    string result="";
    for (int i = 0; i < strs[index].length(); ++i)
    {   bool flag=true;
        for (int j = 0; j < strs.size(); ++j)
        {
            if (strs[index][i]!=strs[j][i])
            {
                    flag=false;
                    break;
            }
        }
        if (flag==true)
        {
            result+=strs[index][i];
        }
     if(flag==false){break;}
    }
    return result;

        
    }
};
