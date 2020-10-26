/*
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break.
You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Example 1:

Input:
N = 2, K = 10
Output: 4
Example 2:

Input:
N = 3, K = 5
Output: 3
Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

Expected Time Complexity : O(N*K)
Expected Auxiliary Space: O(N*K)
*/
int eggDrop(int n, int k) 
{
  int eggFloor[n + 1][k + 1]; 
    int res; 
    int i, j, x; 
    for (i = 1; i <= n; i++) { 
        eggFloor[i][1] = 1; 
        eggFloor[i][0] = 0; 
    } 
    for (j = 1; j <= k; j++) 
        eggFloor[1][j] = j; 
    for (i = 2; i <= n; i++) { 
        for (j = 2; j <= k; j++) { 
            eggFloor[i][j] = INT_MAX; 
            for (x = 1; x <= j; x++) { 
                res = 1 + max( 
                              eggFloor[i - 1][x - 1], 
                              eggFloor[i][j - x]); 
                if (res < eggFloor[i][j]) 
                    eggFloor[i][j] = res; 
            } 
        } 
    } 
  
    return eggFloor[n][k]; 
}
