/*
Anagram
Given two strings a and b consisting of lowercase characters.
The task is to check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains same characters, 
only the order of characters can be different. For example, “act” and “tac” are anagram of each other.
Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of two strings in 'lowercase' only, in a single line.

Output:
Print "YES" without quotes if the two strings are anagram else print "NO".

Constraints:
1 ≤ T ≤ 300
1 ≤ |s| ≤ 106

Example:
Input:
2
geeksforgeeks forgeeksgeeks
allergy allergic

Output:
YES
NO
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 
#include <limits.h>
#include <algorithm> 
int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n;
    cin>>t;
    string s1,s2;
    std::vector<int> v;
        v.push_back(2);
        alpha=96
        m[alpha]=2;
        alpha++;
        int count=0;
        int n=26;
        for(count = 2; count <= n; i++)  
        {
            // iteration to check c is prime or not
            for(c = 2; c < i; c++)
            {
                if(i%c == 0)
                    break;
            }

            if(c == i)  // c is prime
            {   m[alpha]=i;
                alpha++;
                count++;    // increment the count of prime numbers
            }

        }
    while(t--){
        cin>>s1>>s2;
        product_1=1;
        product_2=1;
        for (int i = 0; i < s1.length(); ++i)
        {
            product_1=product_1*m[(int)s1[i]];
        }
        for (int i = 0; i < s2.length(); ++i)
        {
            product_2=product_2*m[(int)s2[i]];
        }
        if (product_2==product_1)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"endl;
        }


std::map<int, int> m;




        
    }
            
    return 0;
}
