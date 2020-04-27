/*
You are given several queries. In the i-th query you are given a single positive integer n i. 
You are to represent n i as a sum of maximum possible number of composite summands and print this maximum number, or print -1, if there are no such splittings.

An integer greater than 1 is composite, if it is not prime, i.e. if it has positive divisors not equal to 1 and the integer itself.

Input
The first line contains single integer q (1 ≤ q ≤ 105) — the number of queries.

q lines follow. The ( i + 1)-th line contains single integer n i (1 ≤ n i ≤ 109) — the i-th query.

Output
For each query print the maximum possible number of summands in a valid splitting to composite summands, or -1, if there are no such splittings.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<cmath> 
#include <limits.h>
void count_n(int n){
	int rem=n%4;
	if (rem==1)
	{	if (n<9)
	{
		cout<<"-1"<<endl;
		return;
	}
		cout<<(n-9)/4+1<<endl;
		return;
	}else if (rem==2)
	{
		cout<<(n-6)/4+1<<endl;
		return;
	}else if(rem==3){
		if (n<15)
		{
			cout<<"-1"<<endl;
			return;
		}else{
			cout<<(n-15)/4+2<<endl;
			return;
		}
	}else{
		cout<<n/4<<endl;
		return;
	}
}
int main(){
	std::ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		int count=0;
		if (n<4)
		{
			cout<<"-1"<<endl;
		}else{
			count_n(n);
		}

	}
	
	return 0;
}