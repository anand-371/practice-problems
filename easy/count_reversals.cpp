/*Count the Reversals
Given a string S consisting only of opening and closing curly brackets '{' and '}' find out the minimum number of reversals required to
 make a balanced expression.

Input
The first line of input contains an integer T, denoting the number of test cases. Then T test cases
follow. The first line of each test case contains a string S consisting only of { and }.*/
#include <iostream>
using namespace std;

int main() {
	int t,n,open,close;
	cin>>t;
	string s;
	while(t--){
	    cin>>s;
	    if(s.length()%2!=0){
	        cout<<"-1\n";
	    }else{
	    int l=0,c=0;
	    for(int i=0;i<s.length();i++){
	        if(s[i]=='{'){
	            l++;
	        }else{
	            l--;
	        }
	        if(l<0){
	            l=1;
	            c++;
	        }
	    }
	    c=c+(l/2);
	    cout<<c<<"\n";
	  }
	       
	    }
	    return 0;
	}
	
