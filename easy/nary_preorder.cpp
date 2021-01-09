/*
N-ary Tree Preorder Traversal
Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 10^4]
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void narypreorder(Node* root,vector<int>&v){
    v.push_back(root->val);
    std::vector<Node*> child=root->children;
    for (int i = 0; i <child.size(); ++i)
    {
        narypreorder(child[i],v);
    }
}

vector<int> preorder(Node* root) {
        std::vector<int> v;
        if(root==NULL){return v;}
        narypreorder(root,v);
        return v;
    }
};
