/*
Level order traversal in spiral form
Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.


 
 

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105

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
}; */

vector<int> findSpiral(Node *root)
{   
    std::vector<int> result;
    if(root==NULL){return result;}
    queue<Node*>q;
    q.push(root);
    int level=0;
    bool flag=false;
    while(!q.empty()){
        int size=q.size();
        std::vector<int>temp_v;
        while(size--){
            Node* temp=q.front();
            q.pop();
            if (flag)
            {
                temp_v.push_back(temp->data);
            }else{
                temp_v.insert(temp_v.begin(),temp->data);
            }

            if (temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if (temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
        flag=!flag;
        for (int i = 0; i < temp_v.size(); ++i)
        {
            result.push_back(temp_v[i]);
        }
        level++;
    }
    return result;
}