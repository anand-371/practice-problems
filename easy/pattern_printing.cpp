/*Print Pattern
Print a sequence of numbers starting with N, without using loop, in which  A[i+1] = A[i] - 5,  if  A[i]>0,
 else A[i+1]=A[i] + 5  repeat it until A[i]=N.

Input:
The first line contains an integer T, number of test cases. Then following T lines contains an integer N.

Output:
For each test case, print the pattern in newline with space separated integers.
*/

#include <iostream>
using namespace std;
void print_pattern(int n){
   if(n>0){
       cout<<n<<" ";
       print_pattern(n-5);
       cout<<n<<" ";
   }else{
       cout<<n<<" ";
   }
}
int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    print_pattern(n);
	    cout<<endl;
	}
	return 0;
}
