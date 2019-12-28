/*Minimum Cost of ropes
There are given N ropes of different lengths, we need to connect these ropes into one rope.
 The cost to connect two ropes is equal to sum of their lengths. 
The task is to connect the ropes with minimum cost.

Input:
The first line of input contains an integer T denoting the number of test cases. 
The first line of each test case is N where N is the number of ropes.
 The second line of each test case contains N input L[i],length of ropes.
*/
#include <iostream>
using namespace std;
#include<queue>
int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    long long int arr[n];
	    long long int sum=0,a=0,b=0;
	    priority_queue <int, vector<int>, greater<int> > pq; 
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        pq.push(arr[i]);
	    }
	    while(pq.size()>1){
	        a=pq.top();
	        pq.pop();
	        b=pq.top();
	        pq.pop();
	        sum+=(a+b);
	        pq.push(a+b);
	    }
	    cout<<sum<<"\n";
	    
	}
	return 0;
}