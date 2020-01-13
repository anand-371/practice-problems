/*Given an array of size N containing level order traversal of a BST.
 The task is to complete the function constructBst(), that construct the BST (Binary Search Tree) from its given level order traversal.

Input:
First line of input contains number of testcases T. For each testcase,
 first line contains number of elements and next line contains n elements which is level order travesal of a BST.
// You are required to complete this function
*/
void con(Node* root,int *a,int n,int i)
{   Node* head=root;
   Node* curr=head;
    while(1)
    {
        if(i==n)
        break;
    if(root==NULL)
    {
        if(a[i]<curr->data)
        {
            Node* temp=new Node(a[i]);
            curr->left=temp;
            i++;
    
        }
        else
        {
            Node* temp=new Node(a[i]);
            curr->right=temp;
            i++;
        
        }
        root=head;
    }
    else{
    if(a[i]<root->data)
    {
        curr=root;
    root=root->left;
    }
    else
    {
        curr=root;
    root=root->right;
    }
    }

    }
}
Node* constructBst(int arr[], int n)
{
    int i=1;
    Node* root=new Node(arr[0]);
    Node* curr=root;
    con(root,arr,n,i);
    return curr;
	
}