/*Maximum of all subarrays of size k
Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
The first line of input contains an integer T denoting the number of test cases.
 The first line of each test case contains a single integer N denoting the size of array and the size of subarray K. 
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
*/

#include <iostream>
using namespace std;
#include<queue>
int main() {
	int t,k;
	cin>>t;
	int n,max;
	while(t--){
	    cin>>n>>k;
	    int arr[n];
	    std::deque<int> q(k);
	    int i;
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(i=0;i<k;i++){
	        while(!q.empty() && arr[i]>=arr[q.back()]){
	            q.pop_back();
	        }
	        q.push_back(i);
	    }
	    for(;i<n;i++){
	        cout<<arr[q.front()]<<" ";
	        while(!q.empty() && q.front()<=(i-k)){
	            q.pop_front();
	        }
	        while(!q.empty() && arr[i]>=arr[q.back()]){
	            q.pop_back();
	        }
	        q.push_back(i);
	    }
	    cout<<arr[q.front()];
	    cout<<endl;
	    }
	 return 0;   
	}
