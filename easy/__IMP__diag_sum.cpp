/*Diagonal Sum In Binary Tree
Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

Input:
The first line consists of T test cases. The first line of every test case consists of N, denoting the number of edges in the tree. The second and third line of every test case consists of N, nodes of the binary tree.
*/
void diagonalSum(Node* root) {
    queue<Node*>q;
    q.push(root);
    Node*temp=NULL;
    int size,sum;
    while(!q.empty()){
        sum=0;
        size=q.size();
        while(size--){
            temp=q.front();
            q.pop();
            while(temp!=NULL){
                sum+=temp->data;
                if(temp->left!=NULL){
                    q.push(temp->left);}
                temp=temp->right;
            }
        }
        cout<<sum<<" ";
    }
    cout<<endl;
    
}