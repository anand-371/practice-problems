/*Given a sorted circular linked list, 
the task is to insert a new node in this circular list so that it remains a sorted circular linked list.
*/
void sortedInsert(Node** head_ref, int x)
{
   struct Node *p = *(head_ref);
   struct Node *q =p;
   struct Node *r =new Node(x);
   if(x < p->data)
   {
       while(q->next!=p)
       {
           q=q->next;
       }
       r->next=q->next;
       q->next=r;
       *(head_ref)=r;
   }
   else if(x==p->data)
   {
       r->next=p->next;
       p->next=r;
   }
   else
   {
       while(q->next->data < x && q->next!=p)
       {
           q=q->next;
       }
       r->next=q->next;
       q->next=r;
   }
}