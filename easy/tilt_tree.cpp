/*Tilt of Binary Tree
Given a binary tree of size N+1, your task is to complete
 the function tiltTree(), that return the tilt of the whole
 tree. The tilt of a tree node is defined as the absolute 
 difference between the sum of all left subtree node values
  and the sum of all right subtree node values. Null nodes 
  are assigned tilt to be zero. Therefore, tilt of the whole
  tree is defined as the sum of all nodes’ til
  */

/*
struct Node {
	int val;
	struct Node *left, *right;
};
*/
// Your are required to complete this function
// function should return the tilt of the tree
int sum(Node*root){
    if(root==NULL){return 0;}
    
    return sum(root->left)+sum(root->right)+root->val;
    
}
int tiltTree(Node* root)
{
	if(root==NULL){return 0;}
	
	int diff=abs(sum(root->left)-sum(root->right));
	return diff+tiltTree(root->left)+tiltTree(root->right);
	
}
