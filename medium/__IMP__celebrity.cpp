/*  The Celebrity Problem
You are in a party of N people, where only one person is known to everyone. Such a person may be present in the party, if yes,
 (s)he doesn’t know anyone in the party. Your task is to find the stranger (celebrity) in party.
You will be given a square matrix M[][] where if an element of row i and column j  is set to 1 it means ith person knows jth person. 
You need to complete the function getId() which finds the id of the celebrity if present else return -1. 
The function getId() takes two arguments, the square matrix M and its size N.

Note: Expected time complexity is O(N) with constant extra space.
*/

int getId(int M[MAX][MAX], int n)
{
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    int a,b;
    
    while(s.size()>1){
        a = s.top();
        s.pop();
        b=s.top();
        s.pop();
        if(M[a][b]==0){
            s.push(a);
        }else{
            s.push(b);
        }
    }
    int c=s.top();
    s.pop();
    if(M[c][a]){
        c=a;
    }
    if(M[c][b]){
        c=b;
    }
    for(int i=0;i<n;i++){
        if(i!=c && (M[c][i]==1||M[i][c]==0)){
            return -1;
        }
    }
    return c;
}