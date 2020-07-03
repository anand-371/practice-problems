/*
Sorted subsequence of size 3
Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of the array A in the next line are N space-separated values of the array A.

Output:
For each test case in a new line, the output will be 1 if the sub-sequence returned by the function is present in array A else 0. If the sub-sequence returned by the function is not in the format as mentioned then the output will be -1.

User Task:
Your task is to complete the function find3Numbers which finds any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k. You need to return them as a vector, if no such element is present then return the empty vector of size 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= 106, for each valid i

Example:
Input:
2
5
1 2 1 1 3
3
1 1 3
Output:
1
0

Explanation:
Test case 1: a sub-sequence 1 2 3 exist.
Test case 2: no such sub-sequence exist.
*/

/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
vector<int> find3Numbers(vector<int> arr, int n) {
    int increasing[n];
      increasing[0]=-1;
      int min=0;
      int decreasing[n];
      decreasing[n-1]=-1;
      for (int i = 1; i < n; ++i)
      {
          if (arr[i]<=arr[min])
          {
              increasing[i]=-1;
              min=i;
          }else{
            increasing[i]=min;
          }
      }
      int max=n-1;
      for (int i = n-2; i >=0; i--)
      {
          if (arr[i]>=arr[max])
          {   decreasing[i]=-1;
              max=i;
          }else{
            decreasing[i]=max;
          }
      }
      std::vector<int> v;
      for (int i = 0; i < n; ++i)
      {
          if (increasing[i]!=-1 && decreasing[i]!=-1)
          {
              
              v.push_back(arr[increasing[i]]);
              v.push_back(arr[i]);
              v.push_back(arr[decreasing[i]]);
              return v;
          }
      }
}
