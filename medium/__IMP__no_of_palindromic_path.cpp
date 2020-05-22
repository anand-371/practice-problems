/*
Number of Palindromic paths in a Matrix
Given a matrix containing lower alphabetical characters only, we need to count number of palindromic paths in given matrix.
 A path is defined as a sequence of cells starting from top-left cell and ending at bottom-right cell. We are allowed to move to right and down only from current cell.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. 
Each test case consists of two lines.
First line of each test case consist of two space separated integers R and C,
 denoting the number of element in a row and column respectively.
Second line of each test case consists of R*C space separated chars denoting the elements in the matrix
 in row major order.
*/
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
const int ma=10;
void dfs(int startx,int starty,int endx,int endy,int &count,char arr[ma][ma],string s){
    if (startx==endx && starty==endy)
    {   s+=arr[startx][starty];
        string r=s;
        reverse(r.begin(),r.end());
        if (r==s)
        {
                count++;
        }
    }
    if (startx>endx || starty>endy)
    {   
        return;
    }
    
    dfs(startx+1,starty,endx,endy,count,arr,s+arr[startx][starty]);
    dfs(startx,starty+1,endx,endy,count,arr,s+arr[startx][starty]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int n,r,c;
    cin>>t;
    while(t--){
       cin>>r>>c;
       char arr[ma][ma];
       for (int i = 0; i <r; ++i)
       {
           for (int j = 0; j < c; ++j)
           {
                cin>>arr[i][j];
           }
       }
       string s="";
       int count=0;
       dfs(0,0,r-1,c-1,count,arr,s);
       cout<<count<<endl;

    

       }
    return 0;


}