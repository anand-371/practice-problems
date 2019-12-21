/*
Given a Cirular Linked List split it into two halves circular lists. 
If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, 
first list should have one node more than the second list. 
The resultant lists should also be circular lists and not linear lists.
You have to complete the method which takes 3 argument: The address of the head of the linked list ,
 addresses of the head of the first and second halved resultant lists.. You should not read any input from stdin/console.
  There are multiple test cases. For each test case, this method will be called individually.
*/

void splitList(Node *head, Node **head1ref, Node **head2ref)
{
    Node *slowptr = head;  
    Node *fastptr = head;  
      
    if(head == NULL)  
        return;  
    while(fastptr->next != head &&  fastptr->next->next != head)  
    {  
        fastptr = fastptr->next->next;  
        slowptr = slowptr->next;  
    }  
      
    if(fastptr->next->next == head)  
        fastptr = fastptr->next;  
    *head1ref = head;  
    if(head->next != head)  
        *head2ref = slowptr->next;  
    fastptr->next = slowptr->next;  
    slowptr->next = head;
}