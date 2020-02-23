#include <iostream>
using namespace std;

int main() {
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		cout<<josephus(n,k)<<"\n";

	}
	return 0;
}

int josephus(int n,int k){
	if(n==1){return 1;}
	else{
		return (josephus(n-1,k)+(k-1))%n+1;
	}
}