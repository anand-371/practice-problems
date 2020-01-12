/*K distance from root
Given a Binary Tree and a number k. Print all nodes that are at distance k from root (root is considered at distance 0 from itself).
 Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.
 Input:
The task is to complete the method which takes two arguments, root of Binary Tree and k. The struct Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes at k distance from root. Nodes should be printed from left to right.
*/
void printKdistance(Node *root, int k)
{   if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }else{
        printKdistance(root->left,k-1);
        printKdistance(root->right,k-1);
    }
}