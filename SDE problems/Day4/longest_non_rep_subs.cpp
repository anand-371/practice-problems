/*
Length of the longest substring
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is str.

Output:

Print the length of longest substring.

Constraints:

1 ≤ T ≤ 20
1 ≤ str ≤ 50

Example:

Input:
2
geeksforgeeks
qwertqwer

Output:
7
5
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while( t-- ){
        string s;
        cin >> s;
        unordered_set<char> m;
        int max_len = 1;
        int temp = 1;
        int i = 0, j = 0;
        m.insert( s[j] );
        j++;
        while( j < s.length() ){
                if( m.find( s[j] ) == m.end() ){
                        m.insert( s[j] );
                        max_len = max( max_len,(int)m.size() );
                    }
                    else{
                    while( i <= j && m.find( s[j] ) != m.end() ){
                                m.erase( s[i] );
                                i++;
                        }
                    m.insert( s[j] );
                    }
                          j++;
                    }
                        cout << max_len << endl;
                    }
            return 0;
            }
