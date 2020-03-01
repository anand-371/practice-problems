/* Right View of Binary Tree
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

// Should print right view of tree
void rightView(Node *root)
{
   if(root==NULL){return;}
    queue<Node*>q;
    q.push(root);
    int level=0,level_no=0;
    int max=-1;
    int size;
    while(1){
        size=q.size();
        if(size==0){break;}
        else if(size>max){max=size;level_no=level;}
        cout<<q.back()->data<<" ";
        while(size>0){
            Node* rt= q.front();
            q.pop();
            if(rt->left!=NULL){q.push(rt->left);}
            if(rt->right!=NULL){q.push(rt->right);}
            size--;
        }
        level++;   
    }
    
}

void leftView(Node *root)
{
  if(root==NULL){return;}
    queue<Node*>q;
    q.push(root);
    int level=0,level_no=0;
    int max=-1;
    int size;
    while(1){
        size=q.size();
        if(size==0){break;}
        else if(size>max){max=size;level_no=level;}
        cout<<q.front()->data<<" ";
        while(size>0){
            Node* rt= q.front();
            q.pop();
            if(rt->left!=NULL){q.push(rt->left);}
            if(rt->right!=NULL){q.push(rt->right);}
            size--;
        }
        
        level++;   
    }
}

