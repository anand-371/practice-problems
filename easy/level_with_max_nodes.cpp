/* Maximum Node Level
Find the level in a binary tree which has the maximum number of nodes. The root is at level 0.

Note: The Input/Output format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. 
The task is to complete the function specified, and not to write the full code.

Input:
The first line consists of T test cases. The first line of every test case consists of N, 
denoting the number of edges in the tree. The second and third line of every test case consists of N, nodes of the binary tree.
*/
int maxNodeLevel(Node *root)
{   if(root==NULL){return -1;}
    queue<Node*>q;
    q.push(root);
    int level=0,level_no=0;
    int max=-1;
    int size;
    while(1){
        size=q.size();
        if(size==0){break;}
        else if(size>max){max=size;level_no=level;}
        while(size>0){
            Node* rt= q.front();
            q.pop();
            if(rt->left!=NULL){q.push(rt->left);}
            if(rt->right!=NULL){q.push(rt->right);}
            size--;
        }
        level++;   
    }
    return level_no;
}

/*
Sum of Leaf Nodes
Given a Binary Tree of size N. The task is to complete the function sumLeaf(), that should return the sum of all the leaf nodes of the given binary tree.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines,
first of which containing the number of edges (between two nodes) in the tree. Next line 
contains N pairs (considering a and b) with a 'L' (means node b on left of a) or 'R' (means node b on right of a) after a and b.
int sumLeaf(Node* root)
{   if(root==NULL){return 0;}
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    return sumLeaf(root->left)+sumLeaf(root->right);
    
}


*/
