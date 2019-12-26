/*
One day Chinky was roaming around the park and suddenly she found N bags with diamonds.
The i'th of these bags contains Ai diamonds. She felt greedy and started to pick up the bag very fastly.
 But due to quick movement, she drops it on the ground. But as soon as she drops the bag, 
 a genie appears in front of her and he increases the number of diamonds in the bag suddenly!
Now the bag which was used to contain P diamonds(before picking up), now contains [P/2] diamonds, 
where [p] is the greatest integer less than p. Then genie gave her the time K minutes in which she can take as many as diamonds.
 In a single minute , she can take all the diamonds in a single bag,
  regardless the number of diamonds in it. Find the maximum number of diamonds that Chinky can take with her.

Input:
First line contains an integer T. T test cases follow.First line of each test case contains two space-separated integers N and K.
Second line of each test case contains N space-separated integers,the number of diamonds in the bags.
*/

#include <iostream>
using namespace std;
#include <cmath>
#include<queue>
int main() {
	long int t,n,k,sum=0,y=0;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    long int arr[n];
	    priority_queue<int>q;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        q.push(arr[i]);
	    }
	    for(int j=0;j<k;j++){
	        y=q.top();
	        sum+=y;
	        y=y/2;
	        q.pop();
	        q.push(y);
	    }
	    cout<<sum<<"\n";
	}
	return 0;
}
