/*Postorder traversal from given Inorder and Preorder traversals
Given a preOrder and inOrder traversal of a binary tree your task is to print the postOrder traversal of the tree .
You are required to complete the function printPostOrder which prints the node of the tree in post order fashion . 
You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.


Input Format:
The task is to complete the function printPostOrder which takes 3 argument, the first being the array of inOrder Traversal of the tree (in) ,
the second beeing the preOrder traversal of the tree (pre) and third being the no of nodes of the Tree (N).
There are multiple test cases. For each test case, this method will be called individually.
*/
int search(int arr[], int x, int n)
{
for (int i = 0; i < n; i++)
if (arr[i] == x)
return i;
return -1;
}
void printPostOrder(int in[], int pre[], int n)
{
int root=search(in,pre[0],n) ;

// If left subtree is not empty, print left subtree
if (root != 0)
printPostOrder(in, pre + 1, root);

// If right subtree is not empty, print right subtree
if (root != n - 1)
printPostOrder(in + root + 1, pre + root + 1, n - root - 1);

// Print root
cout << pre[0] << " ";
//Your code here
}