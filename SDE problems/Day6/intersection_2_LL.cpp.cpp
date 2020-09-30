/*
Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.
*/
 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a_temp=headA;
        ListNode* b_temp=headB;
        while(a_temp!=b_temp){
            if (a_temp==NULL)
            {
                a_temp=headB;
            }else{
                a_temp=a_temp->next;
            }
            if (b_temp==NULL)
            {
                b_temp=headA;
            }else{
                b_temp=b_temp->next;
            }
        }
        return a_temp;
    }