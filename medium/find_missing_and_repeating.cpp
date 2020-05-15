/*
Find Missing And Repeating
Given an unsorted array of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number
 'B' occurs twice in array. Find these two numbers.

Note: If you find multiple answers then print the Smallest number found. Also, expected solution is O(n) time and
 constant extra space.

Input:
The first line of input contains an integer T denoting the number of test cases.
 The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. 
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
*/#include <iostream>
using namespace std;
int main()
{
    int T;
    long long int sum_n, sum_n2, n, curr;
    
    cin>>T;
    for(int t = 0; t<T; t++)
    {
        sum_n =0;
        sum_n2 =0;
        cin>>n;
        for(int i =0; i<n; i++)
        {
            cin>>curr;
            sum_n += curr;
            sum_n2 += (curr)*(curr);
        }
        
        long long int x = (n*(n+1))/2 - sum_n;
        long long int y = ((n*(n+1)*(2*n+1))/6 - sum_n2)/x;
        
        cout<<(y-x)/2<<" "<<(x+y)/2<<endl;
        
        
    }
}