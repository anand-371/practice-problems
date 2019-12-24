/*Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Input:
The first line of input will contains an integer T denoting the no of test cases . 
Then T test cases follow. Each test case contains an integer N denoting the size of the stack. 
Then in the next line are N space separated values which are pushed to the the stack. 

*/

void SortedStack :: sort()
{
   //Your code here
   stack<int> s1;
   int t;
   while(!s.empty()){
       t = s.top();
       s.pop();
       if(s1.empty()){
           s1.push(t);
       }else if(t<s1.top()){
           s1.push(t);
       }else{
           int x;
           while(!s1.empty()&&s1.top()<t){
               x = s1.top();
               s1.pop();
               s.push(x);
           }
           s1.push(t);
       }
   }
   while(!s1.empty()){
       s.push(s1.top());
       s1.pop();
   }
}

//below is the recursive solution for sorting a stack
/*
void SortedStack :: sort()
{
    sort_stack(s);
}
void sort_stack((stack<int> s){
    if(!s.empty()){
        int x=s.top();
        s.pop();
        sort_stack(s);
        Insert_ele(s,x);
    }
}

void Insert_ele(stack<int> s,int x){
    if(s.empty()||s.top()<x){
        push(s,x);
        return;
    }
    int temp=s.top();
    s.pop();
    Insert_ele(s,x);
    push(s,temp);
    
}
*/