/*
Reverse First K elements of Queue
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, 
leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Input Format:
First line consists of T test cases. First line of every test case consists of 2 integers, N and K, 
denoting number of elements and number of elements to be reversed respectively. Second line of every test 
case consists of elements of array.
*/
queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack<ll>s;
    queue<ll>w;
    int top_ele=q.front();
    for(int i=0;i<k;i++){    
        s.push(q.front());
        q.pop();
    }
    while(!q.empty()){
        w.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(!w.empty()){
        q.push(w.front());
        w.pop();
    }
    return q;
    
}