/*"QAQ" is a word to denote an expression of crying. Imagine "Q" as eyes with tears and "A" as a mouth.

Now Diamond has given Bort a string consisting of only uppercase English letters of length n. There is a great number of "QAQ" in the string (Diamond is so cute!).
Bort wants to know how many subsequences "QAQ" are in the string Diamond has given. Note that the letters "QAQ" don't have to be consecutive, but the order of letters should be exact.

Input
The only line contains a string of length n (1 ≤ n ≤ 100). It's guaranteed that the string only contains uppercase English letters.

Output
Print a single integer — the number of subsequences "QAQ" in the string.
*/
#include <iostream>
#include <bits/stdc++.h>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int y=0,count=0;
	int t,n,temp,current=0;
	std::vector<char> v;
	std::map<string,int> map;
	string s;
	cin>>s;
	count=0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i]=='Q')
		{
			count++;
			current+=y;
		}else if(s[i]=='A'){
			y+=count;
		}
	}
	cout<<current<<endl;
	

	}

	
    
		
        
        
        


        

        
        

 