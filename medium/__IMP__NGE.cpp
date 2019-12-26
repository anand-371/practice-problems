/*Next larger element
Given an array A of size N having distinct elements, 
the task is to find the next greater element for each element of the array in order of their appearance in the array.
 If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array.
 The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while(t--) {
	    cin >> n;
	    vector <ll> arr(n), ans(n);
	    
	    for(int i = 0; i < n; i++)
	            cin >> arr[i];
	    stack <ll> s;
	    for(int i = n-1; i >= 0; i--) {
	        while(!s.empty() && arr[i] >= s.top())
	            s.pop();
	        ans[i] = s.empty() ? -1 : s.top();
	        s.push(arr[i]);
	    }
	    
	    for(int i = 0; i < n; i++)
	        cout << ans[i] << " ";
	    cout << endl;
	}
	return 0;
}