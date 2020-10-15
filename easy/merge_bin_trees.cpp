/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1,t2);
    }
TreeNode* merge(TreeNode* t1, TreeNode* t2){
    if (t1==NULL && t2==NULL)
    {
        return NULL;
    }
    if (t1==NULL && t2!=NULL)
    {
        return t2;
    }
    if (t2==NULL && t1!=NULL)
    {
        return t1;
    }
    TreeNode* temp=new TreeNode(t1->val+t2->val);
    temp->left=merge(t1->left,t2->left);
    temp->right=merge(t1->right,t2->right);
    return temp;
}
};
