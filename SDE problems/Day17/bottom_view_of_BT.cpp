/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
 

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be
printed as such 3 1 2.
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Your Task:
This is a functional problem, you don't need to care about input, just complete the function bottomView() which takes the root node of the tree as input and returns an array containing the bottom view of the given tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105

*/

// Method that returns the bottom view.
void verical_order(Node* root,int curr,int hd,map<int,pair<int,int>>&m){
    if (root==NULL)
    {
        return;
    }
    if (m.find(hd)==m.end())
    {
        m[hd]=make_pair(root->data,curr);
    }else{
        pair<int,int> temp=m[hd];
        if (temp.second<=curr)
        {
            m[hd].second=curr;
            m[hd].first=root->data;
        }
    }
    verical_order(root->left,curr+1,hd-1,m);
    verical_order(root->right,curr+1,hd+1,m);
}

vector <int> bottomView(Node *root)
{
    std::map<int,pair<int,int>> m;
    verical_order(root,0,0,m);
    std::vector<int> result;
    for (auto i : m)
    {
        result.push_back(i.second.first);
    }
    return result;

    return result;
}
