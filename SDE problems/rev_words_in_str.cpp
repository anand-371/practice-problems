/*
Reverse words in a string.
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter and returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.' 


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)
*/
string reverseWords(string S) 
{   int start=0;
    int end=0;
    std::vector<string> result; 
    for (int i = 0; i < S.length(); ++i)
    {
        if (S[i]=='.')
        {
            end=i;
            string temp="";
            for (int j = start; j < end; ++j)
            {
                temp+=S[j]
            }
            start=end+1;
            result.push_back(temp);
        }
    }
    string temp="";
    for (int j = start; j < end; ++j)
            {
                temp+=S[j]
            }
    start=end+1;
    result.push_back(temp);
    std::reverse(result.begin(),result.end());
    string out="";
    for (int i = 0; i < result.size(); ++i)
    {   
        if (i!=result.size()-1)
        {
            out+=result[i]+".";
        }else{
            out+=result[i];
        }
        
    }
    return out;
} 
    