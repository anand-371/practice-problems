/*Stock span problem
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to
 calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day,
 for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are
 {1, 1, 1, 2, 1, 4, 6}.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the size of the array. The second line of each test case contains N input C[i].
*/
#include <iostream>
#include <stack>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int s[n],a[n];
	    s[0] = 1;
	    stack<int> st;
	    st.push(0);
	    for(int i=0;i<n;i++){
	        cin >> a[i];
	        if(i!=0){
	            while(!st.empty() && a[st.top()] <= a[i]){
	                st.pop();
	            }
	            s[i] = (st.empty())?(i+1):(i-st.top());
	            st.push(i);
	        }
	    }
        for(int i=0;i<n;i++){
            cout << s[i] << " ";
        }  
	    cout << endl;
	}
	return 0;
}