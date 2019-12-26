/*Min sum formed by digits
given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. 
All digits of given array must be used to form the two numbers.

Input:

The first line of input contains an integer T denoting the number of test cases.
 Then T test cases follow. First line of each test case contains an integer N denoting the size of the array.
 Next line of each test contains N space seperated integers denoting the elements of the array.
*/
#include <iostream>
using namespace std;
#include <queue>
int main() {
	int t;
	int a=0,b=0,num,n;
	cin>>t;
	while(t--){
	    a=0,b=0,num=1;
	    cin>>n;
	    int arr[n];
	    priority_queue<int>q;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        q.push(arr[i]);
	    }
	    while(!q.empty()){
	        a=a+(q.top()*num);
	        q.pop();
	        if(q.empty()){q.push(0);}
	        b=b+q.top()*num;
	        q.pop();
	        num=num*10;
	    }
	    cout<<a+b<<"\n";
	    
	}
	return 0;
}