/* A binary tree node structure

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
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 
Your Task:
You don't need to take input. Just complete the function isBalanced() that takes root node as parameter and returns true, if the tree is balanced else returns false.

Constraints:
1 <= Number of nodes <= 105
0 <= Data of a node <= 106

Expected time complexity: O(N)
Expected auxiliary space: O(h) , where h = height of tree
 */

// This function should return tree if passed  tree 
// is balanced, else false. 
int height(struct Node* node){
        if (node==NULL)
        {
            return 0;
        }
        return std::max(1+height(node->left),1+height(node->right));
    }

bool isBalanced(Node *root)
{
    if (root==NULL)
    {
        return true;
    }
    
    int lt=height(root->left);
    int rt=height(root->right);
    if (abs(lt-rt)<=1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return 1;
    }
    return 0;

}
