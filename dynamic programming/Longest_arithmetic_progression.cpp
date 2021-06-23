/*
Longest Arithmetic Progression
Find longest Arithmetic Progression in an integer array A of size N, and return its length.

More formally, find longest sequence of indices, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic Progression.

Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of length m is an Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2]

Note: The common difference can be positive, negative or 0.



Input Format:

The first and the only argument of input contains an integer array, A.
Output Format:

Return an integer, representing the length of the longest possible arithmetic progression.
Constraints:

1 <= N <= 1000
1 <= A[i] <= 1e9
Examples:

Input 1:
    A = [3, 6, 9, 12]

Output 1:
    4

Explanation 1:
    [3, 6, 9, 12] form an arithmetic progression.

Input 2:
    A = [9, 4, 7, 2, 10]

Output 2:
    3

Explanation 2:
    [4, 7, 10] form an arithmetic progression.
*/
int Solution::solve(const vector<int> &A) {
    int n=A.size();
    if(n==1){return n;}
    std::vector<map<int,int>>store(n);
    int max_len=2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int diff=A[j]-A[i];
            if (store[j].find(diff)==store[j].end())
            {
                store[i][diff]=2;
                max_len=std::max(max_len,store[i][diff]);
            }else{
                store[i][diff]=store[j][diff]+1;
                max_len=std::max(max_len,store[i][diff]);
            }
        }
    }
    return max_len;
}
