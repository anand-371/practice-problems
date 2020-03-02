/*Diameter of Binary Tree
Given a Binary Tree, find diameter of it.
+The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.
 The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded
 (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).
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
int maximum(int a,int b){
    if(a>b){return a;}
    else {return b;}
}
int height(Node* node)
{
    if (node == nullptr)
        return 0;
    return 1 + maximum(height(node->left), height(node->right));
}
int diameter(Node* node)
{
   if(node==NULL){return 0;}
   int max=0;
   int l_t=height(node->left);
   int r_t=height(node->right);
   int root_max=l_t+r_t+1;
   int l=diameter(node->left);
   int r=diameter(node->right);
   int max_val=maximum(l,r);
   
   return maximum(max_val,root_max);
   
}