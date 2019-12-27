/* Valid Substring
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')',
 find out the length of the longest valid substring.

NOTE: Length of smallest the valid substring ( ) is 2.

 

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains a string S consisting only of ( and ).
*/

#include <iostream>
#include <string.h>
using namespace std;
#include<stack>
int findMaxLen(string str);
int main() {
	int t;
	cin>>t;
	string arr;
	stack <char>st;
	while(t--){
	    int count=0;
	    cin>>arr;
	    cout<<findMaxLen(arr)<<"\n";
	}
	 
	return 0;
}
int findMaxLen(string str) 
{ 
    int n = str.length(); 

    stack<int> stk; 
    stk.push(-1); 
    int result = 0; 
    for (int i=0; i<n; i++) 
    {
        if (str[i] == '(') 
          stk.push(i); 
  
        else  
        {  
            stk.pop(); 
            if (!stk.empty()) 
                result = max(result, i - stk.top()); 
            else stk.push(i); 
        } 
    } 
  
    return result; 
} 