/*Remove Half Nodes
Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. 
s it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, 
and not to write the full code.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting number of nodes. 
Second line of every test case consists of 3 elements denoting 2 nodes and a character denoting parent's left child or right child.
*/
Node *removeHalfNodes(Node *root)
{
   if(root==NULL){return root;}
   root->left=removeHalfNodes(root->left);
   root->right=removeHalfNodes(root->right);
   if(root->left && ! root->right){
       return root->left;
   }else if(!root->left && root->right){
        return root->right;   
   }
   return root;
}