/*
Tree Sum Count

Given a binary tree root and an integer k, return the number of unique node to subchild paths there are which sums to k.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root = [1, [1, null, null], [4, [2, null, [3, null, null]], null]]
k = 5
Output
2
Explanation
There's 1 -> 4 and 2 -> 3.

Example 2
Input
Visualize
root = [2, [0, null, [1, null, null]], [3, null, [1, [0, null, null], [2, null, [3, null, null]]]]]
k = 9
Output
1
Explanation
There's 3 -> 1 -> 2 -> 3
*/
void count(Tree* root,vector<int>&path,int k,int &c){
    if (root==NULL)
    {
        return;
    }
    path.push_back(root->val);
    count(root->left,path,k,c);
    count(root->right,path,k,c);
    int sum=0;
    for (int i =path.size()-1; i>=0;i--)
    {
            sum+=path[i];
            if (sum==k)
            {
                    c++;
            }
    }
    path.pop_back();
}

int solve(Tree* root, int k) {
    int c=0;
    std::vector<int>path;
    count(root,path,k,c);
    return c;
}
