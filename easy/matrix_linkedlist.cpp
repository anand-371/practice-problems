/*Question :Given a Matrix mat of N*N size, the task
 is to complete the function constructLinkedMatrix(), that constructs a 2D linked list representation of the given matrix.

Input:
The fuction takes 2 argument as input, first the 2D matrix mat[][] and second an integer variable N, denoting the size of the matrix.
There will be T test cases and for each test case the function will be called separately.

Output:
The function must return the reference pointer to the head of the linked list.
*/
Node* construct(int mat[MAX][MAX],int i,int j, int m,int n){
    if(i>n-1 || j>m-1){return NULL;}
    Node* temp=new Node(mat[i][j]);
    temp->right=construct(mat,i,j+1,m,n);
    temp->down=construct(mat,i+1,j,m,n);
    return temp;
    
}
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    Node* new_list;
    new_list=construct(mat,0,0,n,n);
    return new_list;
}
