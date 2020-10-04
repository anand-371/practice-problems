/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* start=head;
        ListNode* end=head;
        ListNode* prev=head;
        if(k==0){
            return head;
        }
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* count=head;
        int counter=0;
        while(count!=NULL){
            count=count->next;
            counter++;
        }
        if (counter<k)
        {
            k=k%counter;
        }
        while(k--){
        while(end->next!=NULL){
        prev=end;
        end=end->next;
            }
        prev->next=NULL;
        end->next=start;
        start=end;
        end=start;
        
        }
                return start;
    }
};
