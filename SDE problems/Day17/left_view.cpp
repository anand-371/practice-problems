/*
Left View of Binary Tree
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3
*/

vector<int> leftView(Node *root)
{
   queue<Node*>q;
   q.push(root);
   int level=0;
   std::vector<int>final;
   final.push_back(root->data);
   std::vector<vector<int>> result;
   while(!q.empty()){
        std::vector<int>v;
        int size=q.size();
        while(size--){
            Node* temp=q.top();
            v.push_back(temp->data);
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
        result.push_back(v);
        level++;
   }
   for (int i = 0; i < result.size(); ++i)
   {
        final.push_back(result[i][0]);
   }
   return final;
}