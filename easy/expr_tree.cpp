/*Expression Tree
Given a simple expression tree, which is also a full binary tree consisting of basic binary operators i.e.
, + , – ,* and / and some integers, Your task is to evaluate the expression tree.

Input Format:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. 
Each test case contains an integer N denoting the no of nodes. 
Then in the next line are N space separated values of the nodes of the Binary tree filled in continous way from the left to the right.
The structure of node is as follows
struct node{
	string data;
	node *left;
	node *right;
};
*/

/*You are required to complete below method */
int evalTree(node* root)
{
    if(root==NULL){return -1;}
    if(root->left==NULL && root->right==NULL){return stoi(root->data);}
    int left=evalTree(root->left);
    int right=evalTree(root->right);
    if(root->data=="+"){return left+right;}
    else if(root->data=="-"){return left-right;}
    else if(root->data=="*"){return left*right;}
    else{
        return left/right;
    }
    }

