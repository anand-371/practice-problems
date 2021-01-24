/*
Problem Description

Given a sorted array A containing N integers both positive and negative.

You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.

Try to this in O(N) time.


Problem Constraints
1 <= N <= 105.

-103 <= A[i] <= 103



Input Format
First and only argument is an integer array A.



Output Format
Return a integer array as described in the problem above.



Example Input
Input 1:

 A = [-6, -3, -1, 2, 4, 5]
Input 2:

 A = [-5, -4, -2, 0, 1]


Example Output
Output 1:

 [1, 4, 9, 16, 25, 36]
Output 2:

 [0, 1, 4, 16, 25]
*/

vector<int> Solution::solve(vector<int> &A) {
    int max=0;
    std::vector<int> result;
    for (int i = 0; i < A.size(); ++i)
    {
        max=std::max(max,abs(A[i]));
    }
    std::vector<int> bitmap(max+1,0);
    for (int i = 0; i < A.size(); ++i)
    {
            bitmap[abs(A[i])]+=1;
    }
    for (int i = 0; i < bitmap.size(); ++i)
    {
            if (bitmap[i]!=0)
            {   int temp=bitmap[i];
                while(temp--){
                    result.push_back(i*i);
                }
            }
    }
    return result;

}
