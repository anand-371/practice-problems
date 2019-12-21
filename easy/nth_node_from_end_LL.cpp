/*
Nth node from end of linked list
Given a linked list consisting of L nodes and given a number N. 
The task is to find the Nth node from the end of the linked list.

Input:
First line of input contains number of testcase T. For each testcase, 
first line of input contains number of nodes in the linked list and the number N. Next line contains N nodes of linked list.
*/
int getNthFromLast(Node *head, int n)
{
       Node* backward=head;
       Node* forward=head;
       for(int i=0;i<n;i++){
           if(forward!=NULL){
           forward=forward->next;
           }else{
               return -1;
           }
       }
       while(forward!=NULL){
           backward=backward->next;
           forward=forward->next;
       }
       return backward->data;
       
}
