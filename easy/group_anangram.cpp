/*
Group Anagrams Together
Given an array of words, print the count of all anagrams together 
in sorted order (increasing order of counts).
For example, if the given array is {“cat”, “dog”, “tac”, “god”, “act”}, then grouped anagrams are 
“(dog, god) (cat, tac, act)”. So the output will be 2 3.

Input:
First line consists of T test case. First line of every test case consists of N, denoting the number of words in array.
 Second line of every test case consists of words of array.
*/
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main() {
	int t,n;
	cin>>t;
	string temp;

	while(t--){
	    	std::vector<string> v;
	std::vector<int> v1;
	    cin>>n;
	    string s[n];
	    for(int i=0;i<n;i++){
	        cin>>s[i];
	        sort(s[i].begin(),s[i].end());
	    }
	    map<string,int>m;
	    map<string,int>::iterator itr;
	    for(int i=0;i<n;i++){
	        m[s[i]]++;
	    }
	    for(itr=m.begin();itr!=m.end();itr++){
	        v1.push_back(itr->second);
	    }
	    sort(v1.begin(),v1.end());
	    for(int i=0;i<v1.size();i++){
	        cout<<v1[i]<<" ";
	    }
	    cout<<endl;
	    
	    
	}
	return 0;
}