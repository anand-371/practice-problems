//User function Template for C++
/*ZigZag Tree Traversal
Given a binary tree of size N, your task is to complete the function zigZagTraversal(),
 that prints the nodes of binary tree in ZigZag manner.
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function 
// Function takes a single argument as input
// the root of the binary tree
// print a new line after each test case
void zigZagTraversal(Node* root)
{
	// Code here
	deque<Node*> first;
	deque<Node*> second;
	
	first.push_front(root);
	first.push_back(NULL);
	int i=1;
	
	while(!first.empty() || !second.empty()){
	if(i%2!=0){
	    second.push_back(NULL);
	    while(first.front() != NULL){
	        Node* curr = first.front();
	        cout<<curr->data<<" "; 
	        if(curr->left)second.push_front(curr->left);
	        if(curr->right)second.push_front(curr->right);
	        
	        first.pop_front();    
	    }
	    first.pop_front();
	    if(second.front() == NULL)second.pop_front();
	    i++;
	}else{
	    first.push_back(NULL);
	    while(second.front() != NULL){
	        Node* curr = second.front();
	        cout<<curr->data<<" ";
	        if(curr->right)first.push_front(curr->right);
	        if(curr->left)first.push_front(curr->left);
	        
	        second.pop_front();
	        
	    }
	    second.pop_front();
	    if(first.front() == NULL)first.pop_front();
	    i++;
	}    
	}

        
}