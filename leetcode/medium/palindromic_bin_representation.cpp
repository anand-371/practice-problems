/*
Palindromic Binary Representation
Problem Description

Given an integer A find the Ath number whose binary representation is a palindrome.

NOTE:

Consider the 1st number whose binary representation is palindrome as 1, instead of 0
Do not consider the leading zeros, while considering the binary representation.


Problem Constraints
1 <= A <= 2104



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the Ath number whose binary representation is a palindrome.



Example Input
Input 1:

 A = 1
Input 1:

 A = 9


Example Output
Output 1:

 1
Output 2:

 27


Example Explanation*
Explanation 1:

 1st Number whose binary representation is palindrome is 1
Explanation 2

 9th Number whose binary representation is palindrome is 27 (11011)
*/
int convertStringToInt(string s)
{
    int num = 0;
 
    for (int i = 0; i < s.size(); i++) {
        num = num * 2 + (s[i] - '0');
    }
    return num;
}
 
int Solution::solve(int A) {
    if (A==1)
    {
        return 1;
    }
    A--;
    queue<string>q;
    q.push("11");
    while(!q.empty()){
        string temp=q.front();
        q.pop();
        A--;
        if (A==0)
        {
            return convertStringToInt(temp);
        }
        int mid=temp.size()/2;
        if (temp.size()%2==0)
        {
            string c1=temp;
            string c2=temp;
            c1.insert(mid,"0");
            c2.insert(mid,"1");
            q.push(c1);
            q.push(c2);
        }else{
            string ch(1,temp[mid]);
            string c1=temp;
            c1.insert(mid,ch);
            q.push(c1);
        }
    }
    return 0;
}
