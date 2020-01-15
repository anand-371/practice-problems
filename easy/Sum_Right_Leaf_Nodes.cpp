/*Sum of Right Leaf Nodes
Given a Binary Tree of size N, your task is to complete the function rightLeafSum(),
 that should return the sum of all the leaf nodes that are right child of their parent of the given binary tree.
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// right leaf nodes
int rightLeafSum(Node* root)
{
     if(root==NULL){return 0;}
     if(root->right!=NULL && root->right->left==NULL && root->right->right==NULL){
         return root->right->data+rightLeafSum(root->left) ;
     }
     return rightLeafSum(root->left)+rightLeafSum(root->right);
}