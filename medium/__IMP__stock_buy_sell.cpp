/*
Stock buy and sell
he cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in betwee
n those days your profit is maximum.

Input: 
First-line contains the number of test cases T. The first line of each test case contains an integer value N denoting the number of days, 
followed by an array of stock prices of N days. 

Output: 
For each test case, print all of the days with profit in a new line, and if there is no profit then print "No Profit".

User Task:
Complete stockBuySell()  function and print all the days with profit in a single line. And if there is no profit then print "No Profit". 
You do not require to return since the function is void.
*/
// { Driver Code Starts


// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    bool flag=true;
    if (n==1)
    {
        return;
    }
    int i=0;
    while(i<n-1){
        while(i<n-1 && price[i+1]<=price[i]){
            i++;
        }
        if (i==n-1)
        {
            break;
        }
        int buy=i++;
        while((i<n)&& price[i]>=price[i-1]){
            i++;
        }
        int sell=i-1;
        flag=false;
        cout<<"("<<buy<<" "<<sell<<") ";
    }
    if(flag==true){
        cout<<"No Profit";
    }
    cout<<endl;
    return;
}
