/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
IN THE FOLLOWING SOLUTION REVERSING CAN BE FURTHER OPTIMISED WITH LOWER SPACE COMPLEXITY
*/
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
    void reverse(ListNode** start,ListNode** end){
	stack<int>st;
	ListNode* temp=*start;
	while(temp!=*end){
		st.push(temp->val);
		temp=temp->next;
	}
	st.push(temp->val);
                temp=*start;
	while(!st.empty()){
		temp->val=st.top();
		st.pop();
		temp=temp->next;
	}
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start=head;
        ListNode* tail=head;
        int temp=k;
        bool flag=true;
        while(true){
            tail=start;
        	temp=k;
            temp--;
        	while(temp--){
        		if (tail->next==NULL)
        		{	flag=false;
        			break;
        		}
        		tail=tail->next;
        	}
        	if (flag==false)
        	{
        		break;
        	}
       reverse(&start,&tail);
        if (tail->next==NULL)
        {
        	break;
        }
        start=tail->next;
        }
    
        return head;
        
    }
};
