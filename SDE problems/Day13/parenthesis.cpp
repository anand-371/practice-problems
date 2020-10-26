/*
Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true

*/
bool isValid(string s) {
        stack<char>st;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i]=='('||s[i]=='{'|| s[i]=='[')
            {
                st.push(s[i]);
            }else if(s[i]==')'||s[i]=='}'|| s[i]==']'){
                if(st.empty()){return false;}
                if (s[i]==')' && st.top()=='(')
                {
                    st.pop();
                }else if(s[i]=='}' && st.top()=='{'){
                    st.pop();
                }else if (s[i]==']' && st.top()=='[')
                {
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.empty()){return true;}
        else{return false;}
        
    }
