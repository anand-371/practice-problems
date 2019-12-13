/*
Given a Circular Linked List of size N. The task is to delete the given node (excluding the first and last node) in circular linked list and then print the reverse of the circular linked list.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the circular linked list. The next line contains n space separated integers forming the circular linked list. The last line contains the node to be deleted in between the circular linked list.

Output:
Print the reverse of the circular linked list with the deleted node.
*/
void deleteNode(struct Node **head, int key)
{
    Node* temp=*head;
    Node * prev=temp;
    temp=temp->next;
    while(temp!=*head){
        if(temp->data==key){
            prev->next=temp->next;
            free(temp);
            return;
        }
        prev=temp;
        temp=temp->next;
    }
}
/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    if (*head_ref == NULL) 
        return; 

    Node* prev = NULL; 
    Node* current = *head_ref; 
    Node* next; 
    do { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } while (current != (*head_ref)); 
  
    (*head_ref)->next = prev; 
    *head_ref = prev; 
} 