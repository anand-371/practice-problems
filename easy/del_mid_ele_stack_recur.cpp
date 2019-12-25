/*Delete middle element of a stack
Given a stack with push(), pop(), empty() operations, delete middle of it without using any additional data structure.
Middle: ceil(size_of_stack/2.0)

Input Format:
The first line contains an integer T, the number of test cases. For each test case,
 the first line contains an integer sizeOfStack denoting the stack size.
 Next line contains space separated integers that will be pushed into the stack.
*/

stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
    if(current==ceil(sizeOfStack/2)){
        s.pop();
        return s;
    }
    
    int x=s.top();
    s.pop();
    stack<int> temp= deleteMid(s,sizeOfStack,current+1);
    temp.push(x);
    return temp;
}
