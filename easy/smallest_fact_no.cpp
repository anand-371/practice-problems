/*

Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Examples:
Input : n = 1
Output : 5
1!, 2!, 3!, 4! does not contain trailing zero.
5! = 120, which contains one trailing zero.
*/
#include <iostream>
using namespace std;

int main() {
	int t,n,k;
	cin>>t;
	while(t--){
	    int count=0;
	    cin>>n;
	    for(int i=5;i<500;i=i+5){
	        k=i;
	        while(k%5==0){
	            count++;
	            k=k/5;
	        }
	        if(count>=n){
	            cout<<i;
	            break;
	        }
	    }
	    cout<<endl;
	}
	return 0;
}