/*  linked list of strings forms a palindrome
Given a linked list of strings having n nodes check to see whether the combined string formed is palindrome or not. 

Input:
You have to complete the method which takes one argument: the head of the linked list . You should not read any input from stdin/console.. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return True if the combined string is pallindrome else it should return False.
*/

bool compute(Node* root)
{
   string str="";
   while(root!=NULL){
       str.append(root->data);
       root=root->next;
   }
   int length=str.length();
   for(int i=0;i<length/2;i++){
       if(str[i]!= str[length-i-1]){
           return false;
       }
   }
   return true;
}