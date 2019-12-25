/*Maximum Rectangular Area in a Histogram
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
 For simplicity, assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. 
In each test cases, the first line contains an integer 'N' denoting the size of array. 
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 The elements of the array represents the height of the bars.
*/

#include <iostream>
#include<stack>
using namespace std;
long long int getmaxarea(long long int arr[],long long int n);
int main() {
	long long int  t,n,left,right;
	cin>>t;
	while(t--){
	    cin>>n;
	    long long int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<getmaxarea(arr,n)<<"\n";
;	    
	}
	return 0;
}


long long int getmaxarea(long long int arr[],long long int n){
    long long int i=0;
    stack<int>s;
    long long int max_area=0;
    long long int area_with_top=0;
    while(i<n){
        if(s.empty()||arr[s.top()]<=arr[i]){
            s.push(i++);
        }else{
            int x=s.top();
            s.pop();
            if(s.empty()){
                area_with_top=arr[x]*i;
            }else{
                area_with_top=arr[x]*(i-s.top()-1);
            }
            if(max_area<area_with_top){
                max_area=area_with_top;
            }
            
        }
        
    }
    while(s.empty()==false){
        int x=s.top();
        s.pop();
        if(s.empty()){
                area_with_top=arr[x]*i;
            }else{
                area_with_top=arr[x]*(i-s.top()-1);
            }
            if(max_area<area_with_top){
                max_area=area_with_top;
            }
    }
    return max_area;
}