/*First non-repeating character in a stream
Given an input stream of N characters consisting only of lower case alphabets. 
The task is to find the first non repeating character, each time a character is inserted to the stream.
 If no non repeating element is found print -1.

Input:
The first line of input contains an integer T denoting the no of test cases.
 Then T test cases follow. Each test case contains an integer N denoting the size of the stream.
 Then in the next line are x characters which are inserted to the stream.
*/
#include <iostream>
using namespace std;
#include<queue>
int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<char> ch(n);
	    queue<char>q;
	    for(int i=0;i<n;i++){
	        cin>>ch[i];
	    }
	    int freq[26];
	    for(int i=0;i<26;i++){
	        freq[i]=0;
	    }
	    for(int i=0;i<n;i++){
	        	 freq[ch[i]-'a']++;
	             q.push(ch[i]);
	             while(!q.empty()){
	                 if(freq[q.front()-'a'] >1){
	                     q.pop();
	                 }else{
	                     cout<<q.front()<<" ";
	                     break;
	                 }
	             }
	             if(q.empty()){
	                 cout<<"-1 ";
	             }
	    }
	    cout<<endl;
	    
	}
	return 0;
}