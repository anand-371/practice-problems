/*First negative integer in every window of size k
Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case contains an integer n denoting the size of the array. 
The next line contains n space separated integers forming the array. 
The last line contains the window size k.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
 int T;
	cin >> T;
	while(T--)
	{
	  int n,k;
	  cin >> n;
	  int arr[n];
	  queue <int> neg;
	  for(int i = 0; i < n; ++i)
	      cin >> arr[i];
	  cin >> k;
	  for(int i = 0; i < k; ++i)
	      if(arr[i] < 0) neg.push(arr[i]);
	  for(int i = k; i <= n - 1; ++i)
	  {
	      if(neg.size() != 0)
	      cout<<neg.front()<<" ";
	      else cout<<"0 ";
	      if(arr[i-k] < 0) neg.pop();
	      if(arr[i] < 0) neg.push(arr[i]);
	  }
	   if(neg.size() != 0)
	      cout<<neg.front()<<" ";
	      else cout<<"0 ";
	  cout<<"\n";
	}
	return 0;
}