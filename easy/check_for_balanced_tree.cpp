/*Check for Balanced Tree
 Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more 
than one for all nodes of tree. 
 A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return tree if passed  tree 
// is balanced, else false. 
int height(Node* root)
{
    // Base case: empty tree has height 0
    if (root == nullptr)
        return 0;

    // recur for left and right subtree and consider maximum depth
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node *root)
{   if(root==NULL){return true;}
    int diff=height(root->left) - height(root->right);
    if(diff>1){return false;}
    return(isBalanced(root->left)&&isBalanced(root->right)&&(abs(height(root->right)-height(root->left))<=1));
}
