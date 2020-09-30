/**
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
    void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
bool compareLists(struct Node* head1, struct Node* head2) 
{ 
    struct Node* temp1 = head1; 
    struct Node* temp2 = head2; 
  
    while (temp1 && temp2) { 
        if (temp1->data == temp2->data) { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else
            return 0; 
    } 
  

    if (temp1 == NULL && temp2 == NULL) 
        return 1; 

    return 0; 
}
bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* mid=NULL;
        ListNode* prev_slow=head;
        ListNode* second=NULL;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            prev_slow=slow;
            slow=slow->next;
        }
        if (fast!=NULL)
        {
            mid=slow;
            slow=slow->next;
        }
        second=slow;
        prev_slow->next=NULL;
        reverse(&second);
        res = compareLists(head, second_half);
        if (res=1)
        {
            return true;
        }else{
            return false;
        }

    }
