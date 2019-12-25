/*Smallest number on left
Given an array of integers, find the nearest smaller number for every element such that the smaller element is on left side.
If no small element present on the left print -1.

Input:

The first line of input contains T test cases. 

The first line of each test case contains the number of elements in the array.

The second line of each test case contains the elements of the array.
*/

#include <iostream>
#include <stack>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int s[n],a[n];
	    for(int i=0;i<n;i++){
	        cin>>s[i];
	    }
	    stack<int>st;
    st.push(s[0]);
    cout<<"-1"<<" ";
    for(int i=1;i<n;i++){
        while(!st.empty() && st.top()>s[i]){
                st.pop();
                }
        if(st.empty()){
            cout<<"-1"<<" ";
        }else{
            cout<<st.top()<<" ";
        }        
        st.push(s[i]);
    }
    
    cout<<endl;
	}
	return 0;
}