/*
Given a singly linked list of 0s and 1s, the task is to find its decimal equivalent. Decimal Value of an empty linked list is considered as 0.

Since the answer can be very large, answer modulo 1000000007 should be printed.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains 

Output:
The function should return should decimal equivalent modulo 1000000007.

User Task:
The task is to complete the function decimalValue() which should find the decimal value of the given binary value in the linked list.

Constraints:
1 <= T <= 200
0 <= N <= 100
Data of Node is either 0 or 1

Example:
Input:
2
3
0 1 1    
4
1 1 1 0

Output:
3
14

Explanation:
Testcase 1: 1*20 + 1*21 + 0*22 =  1 + 2 + 0 = 3.
*/
// { Driver Code Starts
// Program to check if linked list is empty or not
#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;

/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

long long unsigned int decimalValue(struct Node *head);

void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{

    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isEmpty(struct Node *head);

/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

        cout << decimalValue(head) << endl;
    }
    return 0;
}// } Driver Code Ends


/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

// Should return decimal equivalent modulo 1000000007 of binary linked list 

long long unsigned int decimalValue(Node *head)
{
   long long unsigned int count=0;
   long long unsigned int num=1;
   while(head!=NULL){
   if (head->data==1)
   {
       count=(((count<<1)%MOD)+1)%MOD;
   }else{
        count=(count<<1)%MOD;
   }
   head=head->next;
}
return count;
}
