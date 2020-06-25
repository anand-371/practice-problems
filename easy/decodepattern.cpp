/*
Given a pattern as below and an integer n your task is to decode it and print nth row of it. The pattern follows as :
1
11
21
1211
111221
............

Input:
The first line of input is the number of test cases .  Then T test cases follow . The first line of each test case is an integer N.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 
#include <limits.h>
#include <algorithm>

string countnndSay(int n) 
{ 

    if (n == 1)      return "1"; 
    if (n == 2)      return "11"; 
    string str = "11"; 
    for (int i = 3; i<=n; i++) 
    {  
        str += '$'; 
        int len = str.length(); 
        int cnt = 1;  
        string  tmp = ""; 
        for (int j = 1; j < len; j++) 
        { 
            if (str[j] != str[j-1]) 
            {  
                tmp += cnt + '0'; 
                tmp += str[j-1];  
                cnt = 1; 
            } 
            else cnt++; 
        } 
        str = tmp; 
    } 
  
    return str; 
} 
int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<countnndSay(n)<<endl;
        }

    }


    }

