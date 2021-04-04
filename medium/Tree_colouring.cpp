/**
Tree Coloring

 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 
 You are given a binary tree root where the value of each node represents its color. In the tree there are at most 2 colors. Return whether it's possible to swap the colors of the nodes any number of times so that no two adjacent nodes have the same color.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root = [1, [1, null, null], [1, [0, null, [0, null, null]], [0, null, null]]]
Output
true
Explanation
We can color the root with 0, the next level 1s, third level 0s and fourth level 1s

Example 2
Input
Visualize
root = [5, null, [9, [5, null, null], [9, null, null]]]
Output
false
Explanation
There's no way to color the nodes so that no two adjacent nodes have the same color.
 */
void traverse(Tree* root,map<int,int>&curr_col){
    if (root==NULL)
    {
        return;
    }
    traverse(root->left,curr_col);
    curr_col[root->val]++;
    traverse(root->right,curr_col);
}

bool solve(Tree* root) {
    if (root==NULL ||(root->left==NULL && root->right==NULL))
    {
        return true;
    }
    std::map<int,int>curr_col;
    traverse(root,curr_col);
    for(auto i:curr_col){
        cout<<i.first<<" "<<i.second<<endl;
    }
    int defa_color1=curr_col[root->val];
    int defa_color2;
    for(auto x:curr_col){
        if (x.first!=root->val)
        {
            defa_color2=x.second;
        }
    }
    cout<<"-------"<<defa_color1<<" "<<defa_color2<<endl;
    int level=0;
    queue<Tree*>q;
    q.push(root);
    std::map<int, int> m;
    int flag=0;
    while(!q.empty()){
        int size=q.size();
        //cout<<size<<endl;
        if(flag==0){flag=1;m[flag]+=size;}
        else{flag=0;m[flag]+=size;}
        while(size--){
            Tree* temp=q.front();
            q.pop();
            if (temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if (temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
        level++;
    }
    int col1=m[0];
    int col2=m[1];
    cout<<col1<<" "<<col2<<endl;
    return((col1==defa_color1 && col2==defa_color2)||(col1==defa_color2 && col2==defa_color1));

}
