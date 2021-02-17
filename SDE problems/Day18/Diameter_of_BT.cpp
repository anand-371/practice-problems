/* 
Diameter of Binary Tree
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. The diagram below shows two trees each with diameter nine,
the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).


Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000
Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Computes the diameter of binary tree with given root.  */
int height(struct Node* node){
        if (node==NULL)
        {
            return 0;
        }
        return 1+std::max(height(node->left),height(node->right));
    }
int diameter(Node* root) {
    if(root==NULL){return 0;}
    int temp1=height(root->left)+height(root->right)+1;
    int temp2=diameter(root->left);
    int temp3=diameter(root->right);
    return std::max(temp1,std::max(temp2,temp3));
}
