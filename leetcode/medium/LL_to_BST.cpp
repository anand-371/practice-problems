/**
Linked List to Binary Search Tree
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 Given a sorted linked list node of size n, construct a binary search tree by

Taking the value of the k = floor(n / 2)(0-indexed) smallest node and setting it as the root.
Recursively constructing the left subtree using the linked list left of the kth node.
Recursively constructing the right subtree using the linked list right of the kth node.
Constraints

n ≤ 100,000
 */
LLNode* middle(LLNode* node){
    if (node==NULL)
    {
        return NULL;
    }
    if (node->next==NULL)
    {
        return node;
    }
    LLNode* prev=NULL;
    LLNode* slow=node;
    LLNode* fast=node;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if (prev!=NULL)
    {
        prev->next=NULL;
    }
    return slow;
}

Tree* convert(LLNode* node){
    if (node==NULL)
    {
        return NULL;
    }
    LLNode* mid=middle(node);
    Tree* root=new Tree(mid->val);
    if (node==mid)
    {
        return root;
    }
    root->left=convert(node);
    root->right=convert(mid->next);
    return root;
}

Tree* solve(LLNode* node) {

    return convert(node);

}
