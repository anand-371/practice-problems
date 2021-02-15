
/* 
Right View of Binary Tree
A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2
Example 2:

Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
Your Task:
Just complete the function rightView() that takes node as parameter and returns the right view as a list. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105.
 


*/

// Should return  right view of tree
vector<int> rightView(Node *root)
{
   std::vector<int>final;
   if(root==NULL){return final;}
      queue<Node*>q;
   q.push(root);
   int level=0;
   std::vector<vector<int>> result;
   while(!q.empty()){
        std::vector<int>v;
        int size=q.size();
        while(size--){
            Node* temp=q.front();
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
   {    int curr=result[i].size();
        final.push_back(result[i][curr-1]);
   }
   return final;
}
