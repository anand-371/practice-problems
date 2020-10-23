/**
Merge two sorted linked lists and return 
it as a new sorted list. 
The new list should be made by splicing together 
the nodes of the first two lists.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode(0);
        ListNode* ans=temp;
        if (l1==NULL && l2==NULL)
        {
            return NULL;
        }
        if (l1==NULL)
        {
            return l2;
        }
        if (l2==NULL)
        {
            return l1;
        }   
        while(l1 && l2){
            if (l1->val==l2->val)
            {
                ans->next=l1;
                ans=ans->next;
                l1=l1->next;
                ans->next=l2;
                ans=ans->next;
                l2=l2->next;
            }
            else if (l1->val<l2->val)
            {
                ans->next=l1;
                ans=ans->next;
                l1=l1->next;
            }else{
                ans->next=l2;
                ans=ans->next;
                l2=l2->next;
            }
        }
        if (l1==NULL)
        {
            ans->next=l2;
        }else{
            ans->next=l1;
        }
        return temp->next;
}
};