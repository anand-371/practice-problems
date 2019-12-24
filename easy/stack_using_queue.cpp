/*Stack using two queues
Implement a Stack using two queues q1 and q2.

Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)
The second line of each test case contains Q queries seperated by space.
*/

//this program using only one queue to complete the following operations
void QueueStack :: push(int x)
{
        q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{       int result=-1;
        if(q1.empty()){return -1;}   
        q1.push(0);
        while(1){
            int x=q1.front();
            q1.pop();
            if(q1.front()==0){
                result=x;
                break;
            }else{
                q1.push(x);
            }
        }
        q1.pop();
        return result;
}
