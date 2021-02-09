/*
Count And Say
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.
*/
string Solution::countAndSay(int A) {
    if(A==1){return "1";}
    if(A==2){return "11";}
    std::vector<string>v;
    v.push_back("1");
    v.push_back("11");
    A--;
    A--;
    while(A--){
        string curr=v[v.size()-1];
        int count=1;
        string temp="";
        for (int i = 1; i < curr.size(); ++i)
        {
            if (curr[i]==curr[i-1])
            {
                count++;
            }else{
                temp+=to_string((char)count)+curr[i-1];
                count=1;
            }
        }
        temp+=to_string((char)count)+curr[curr.size()-1];
        v.push_back(temp);
    }
    return v[v.size()-1];
}
