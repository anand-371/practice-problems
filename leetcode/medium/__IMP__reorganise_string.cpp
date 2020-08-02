/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
*/
class Solution {
public:
string reorganizeString(string S) {
        std::map<char, int> m;
        int max=0;
        for (auto ch:S)
        {
            m[ch]++;
            max=std::max(max,m[ch]);
        }
        if (max>(S.length()+1)/2)
        {
            return "";
        }
        priority_queue<pair<int,char>>pq;
        for (auto x:m)
        {
            pq.push({x.second,x.first});
        }
    string res;
        while(!pq.empty()){
            pair<int,char> p1=pq.top();             
            pq.pop();
            res+=p1.second;
            
            pair<int,char> p2;
            if(!pq.empty()){                
                p2=pq.top();                
                pq.pop();            
                res+=p2.second;
            }
            
            if((p1.first)>1)
                pq.push({p1.first-1,p1.second});
            if((p2.first)>1)
                pq.push({p2.first-1,p2.second});
        }
        return res;
        }
    
    

    
};
