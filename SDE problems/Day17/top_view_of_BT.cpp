/*
Top View of Binary Tree
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Print from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function printTopView() that takes root node as parameter and prints the top view. Print endline after end of printing the top view.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
1 <= Node Data <= 105
 
*/

void verical_order(Node* root,int curr,int hd,map<int,pair<int,int>>&m){
    if (root==NULL)
    {
        return;
    }
    if (m.find(hd)==m.end())
    {
        m[hd]=make_pair(root->data,curr);
    }else if(m[hd].second>curr){
         m[hd]=make_pair(root->data,curr);
    }
    verical_order(root->left,curr+1,hd-1,m);
    verical_order(root->right,curr+1,hd+1,m);
}

vector<int> topView(struct Node *root)
{
    std::map<int,pair<int,int>> m;
    verical_order(root,0,0,m);
    std::vector<int> result;
    for (auto i : m)
    {
        result.push_back(i.second.first);
    }
    return result;

}
