/*  Get minimum element from stack
You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow. 
First line of each test case contains an integer Q denoting the number of queries.
A Query Q may be of 3 Types:
    1. 1 x (a query of this type means  pushing 'x' into the stack)
    2. 2 (a query of this type means to pop element from stack and print the poped element)
    3. 3 (a query of this type means to print the minimum element from the stack)
The second line of each test case contains Q queries seperated by space.
*/
int _stack :: getMin()
{
    if(s.empty())
        return -1;
    return s.top();
}
/*returns poped element from stack*/
int _stack ::pop()
{ int x;
    if(s.empty())
        { return -1;
        }
        else
        { s.pop();
        x=s.top();
        s.pop();
        if(!s.empty())
            minEle = s.top();
        return x;
    }
}
/*push element x into the stack*/
void _stack::push(int x)
{
        if(s.empty())
            { s.push(x);
                minEle=x;
                s.push(minEle);
            }
            else
            {s.push(x);
            if(x < minEle)
                minEle = x;
                s.push(minEle);
            }
            }