/* Transform to Sum Tree
Given a Binary Tree of size N , where each node has positive and negative values. Convert this to a tree 
where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes
 are changed to 0.
A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
int operation(Node*node){
    if(node==NULL){return 0;}
    int left=operation(node->left);
    int right=operation(node->right);
    int temp=node->data;
    node->data=left+right;
    return temp+node->data;
}
void toSumTree(Node *node)
{   
    if(node==NULL){return;}
    operation(node);
}