/*
Given two linked list of size N1 and N2 respectively of distinct elements, your task is to complete the function countPairs(), which returns the count of all pairs from both lists whose sum is equal to the given value X.

Input:
The function takes three arguments as input, reference pointer to the head of the two linked list (head1 and head2), and an variable X.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test case the function should return the count of all the pairs from both lists whose sum is equal to the given value X. 
*/
int countPairs(struct Node* head1, struct Node* head2, int x)
{
    //Code here
    int count = 0;
    Node *p1, *p2;
    for (p1 = head1; p1 != NULL; p1 = p1->next){
        for (p2 = head2; p2 != NULL; p2 = p2->next){
            if ((p1->data + p2->data) == x){
                count++;
            }
        }
    }

return count;
}