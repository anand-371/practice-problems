/*Convert Ternary Expression to Binary Tree     
Given a string that contains ternary expressions. The expressions may be nested. You need to convert the given ternary expression to a binary Tree and return the root.

Input Format:
First line of input contains of test case T. The only line of test case consists of String s.
*/
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows
struct Node{
	char data;
	Node *left,*right;
};
*/
Node *convertExpression(string str,int i)
{   int l=str.length();
    if(i>=l){return NULL;}
    Node* root;
     if(str[i]!='?' && str[i]!=':'){
        root =new Node(str[i]);
    }
    if(str[i+1]=='?'){
        root->left=convertExpression(str,i+2);
    }else if(str[i+1]==':'){
        root->right=convertExpression(str,i+2);
    }
    return root;
}