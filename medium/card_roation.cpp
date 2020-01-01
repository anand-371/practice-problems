/*Card Rotation 
Given a sorted deck of cards numbered 1 to N.

1) We pick up 1 card and put it on the back of the deck.

2) Now, we pick up another card , it turns out to be card numbered 1 , we put it outside the deck.

3) Now we pick up 2 cards and put it on the back of the deck.

4) Now, we pick up another card and it turns out to be card numbered 2 , we put it outside the deck. ...

We perform this step till the last card.

If such arrangement of decks is possible, output the arrangement, if it is not possible for a particular value of N then output -1.

Input:

The first line of the input contains the number of test cases 'T', after that 'T' test cases follow. 
Each line of the test case consists of a single linecontaining an integer 'N'.
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;   cin>>t;
	while (t--)
	{
	    int n;    cin>>n;
	    int arr[n];
	    queue<int> q;
	    for (int i=0; i<n; i++) 
	        q.push(i);
	    for (int i=1; i<=n; i++)
	    {
	        int j = i; 
	        while (j--)   {
	            q.push(q.front());
	            q.pop();
	            }
	        arr[q.front()]=i;  q.pop();
	    }
	    for (int i=0; i<n; i++) 
	        {cout<<arr[i]<<" ";}
	    cout<<"\n";
	}
	return 0;
}