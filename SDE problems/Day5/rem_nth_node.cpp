/**
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.
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
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
    n--;
        while(n--){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
    cout<<slow->val;
    if(prev==NULL){
        head=head->next;
    }else{prev->next=slow->next;}
        
        return head;
    }
};
