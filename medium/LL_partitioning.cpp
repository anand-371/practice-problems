/*
Linked List Partitioning
You are given a singly linked list node and an integer k. Order the linked list so that all nodes whose values are less than k come first, all nodes whose values
are equal to k next, and then other nodes last.

The relative ordering of the nodes should remain the same.

Bonus: Can you do it in \mathcal{O}(n)O(n) time and \mathcal{O}(1)O(1) space?

Constraints

n ≤ 100,000 where n is the number of nodes in node
*/
LLNode* solve(LLNode* node, int k) {
    LLNode* lh;
    LLNode* mh;
    LLNode* rh;
    LLNode* left=new LLNode(-1);
    lh=left;
    LLNode* middle=new LLNode(-1);
    mh=middle;
    LLNode* right=new LLNode(-1);
    rh=right;
    LLNode* temp=node;
    int count1=0;
    int count2=0;
    int count3=0;
    while(temp!=NULL){
        if (temp->val<k)
        {
            left->next=temp;
            left=left->next;
            count1++;
        }else if (temp->val==k)
        {
            middle->next=temp;
            middle=middle->next;
            count2++;
        }else if (temp->val>k)
        {
            right->next=temp;
            right=right->next;
            count3++;
        }
        temp=temp->next;
    }
    
    lh=lh->next;
    rh=rh->next;
    mh=mh->next;

    if (count1==0 && count2==0 && count3==0)
    {
        return NULL;
    }
    else if (count1==0 && count2!=0 && count3!=0)
    {
        lh=mh;
        middle->next=rh;
        right->next=NULL;
    }
    else if (count1==0 && count2!=0 && count3==0)
    {
        lh=mh;
        middle->next=NULL;
    }
    else if (count1==0 && count2==0 && count3!=0)
    {
        lh=rh;
        right->next=NULL;
    }
    else if (count1!=0 && count2==0 && count3==0)
    {
        left->next=NULL;
    }
    else if (count1!=0 && count2!=0 && count3==0)
    {   
        left->next=mh;
        middle->next=NULL;
    }
    else if (count1!=0 && count2==0 && count3!=0)
    {   
        left->next=rh;
        right->next=NULL;
    }else{
        left->next=mh;
    middle->next=rh;
    right->next=NULL;
    }

    return lh;

}
