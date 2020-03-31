/*
Given a M X N matrix with your initial position at top-left cell, 
find the number of possible unique paths to reach the bottom right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or
matrix[i][j+1] from matrix[i][j].

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an two 
integers A and B depicting the size of the grid.
*/
#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	int a,b;
	while(t--){
	    cin>>a>>b;
        int arr[a][b];
        for(int i=0;i<a;i++){
                arr[i][0]=1;
        }
        for(int i=0;i<b;i++){
                arr[0][i]=1;
        }
        for(int i = 1; i < a; i++) {
            for(int j = 1; j < b; j++) {
                arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
                }
            }
        cout<<arr[a-1][b-1];    
	    cout<<endl;
	}

	return 0;
}