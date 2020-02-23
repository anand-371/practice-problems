/*There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed. The counting begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise). In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
Consider if n = 5 and k = 2, then the safe position is 3.
Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. The first and only line of each test case consists of two space separated positive integers denoting n and k.
*/

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
