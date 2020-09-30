/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Follow up:

Can you solve it using O(1) (i.e. constant) memory?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) 
            return false;
        ListNode* slow = head, * fast = head ;
        while(fast->next && fast->next->next){
            fast = fast->next->next; 
            slow = slow->next;
            if(fast == slow) 
                return true;
        }
	return false;
    }
};
