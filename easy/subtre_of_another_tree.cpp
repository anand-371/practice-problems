/**

https://leetcode.com/problems/subtree-of-another-tree/


 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void find_preorder(TreeNode* root,string&s){
    if (root==NULL)
    {
        return;
    }
    s+=" ";
    s+=(std::to_string)(root->val);
    s+=" ";
    if(root->left==NULL){s.push_back('l');}
    if(root->right==NULL){s.push_back('r');}
    find_preorder(root->left,s);
    find_preorder(root->right,s);
}
 bool isSubtree(TreeNode* s, TreeNode* t) {
        string s1,s2;
        find_preorder(s,s1);
        find_preorder(t,s2);
     cout<<s1<<endl<<s2<<endl;
        if (strstr(s1.c_str(),s2.c_str())) {
            return true;
        }else{
            return false;
        }
        
    }
};
