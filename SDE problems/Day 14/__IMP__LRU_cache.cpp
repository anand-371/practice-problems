/*
Least Recently Used Cache
Implement a least recently used cache with the following methods:

LRUCache(int capacity) constructs a new instance of a LRU cache with the given capacity.
get(int key) retrieves the value associated with the key key. If it does not exist, return -1. As a side effect, this key now becomes the most recently used key.
set(int key, int val) updates the key key with value val. If updating this key-value pair exceeds capacity, then evicts the least recently used key-value pair.
Each method should be done in \mathcal{O}(1)O(1) time.

Constraints

n ≤ 100,000 where n is the number of calls to get and set.
Example 1
Input
methods = ["constructor", "set", "get", "set", "set", "set", "get", "get"]
arguments = [[3], [1, 10], [1], [2, 20], [3, 30], [4, 40], [1], [4]]`
Output
[null, null, 10, null, null, null, -1, 40]
Explanation
We create an LRUCache of capacity 3.

Set key of 1 to value 10. Size of cache is now 1
We get 1 which has value of 10
Set key of 2 to value 20. Size of cache is now 2
Set key of 3 to value 30. Size of cache is now 3
Set key of 4 to value 40. Size exceeds capacity, so now we evict the least recently used key which is 1.
We get 1 which has been evicted so we return -1
We get 4 which has value of 40
*/
#include <bits/stdc++.h>
class LRUCache {
    public:
         list<int>q;
        std::map<int,pair<list<int>::iterator,int>> m;
        int size;
    LRUCache(int capacity) {
        size=capacity;
    }

    int get(int key) {
        if (m.find(key)!=m.end())
        {
                int temp=m[key].second;
                q.erase(m[key].first);
                q.push_front(key);
                m[key].first=q.begin();
                return temp;
        }else{
            return -1;
        }
    }

    void set(int key, int val) {
        if (m.find(key)!=m.end())
        {
                int temp=m[key].second;
                q.erase(m[key].first);
                q.push_front(key);
                m[key].first=q.begin();
                m[key].second=val;
        }else{
            if (q.size()==size)
            {
                int temp=q.back();
                q.pop_back();
                m.erase(temp);
                q.push_front(key);
                m[key].first=q.begin();
                m[key].second=val;

            }else{
                q.push_front(key);
                m[key].first=q.begin();
                m[key].second=val;
            }
        }
    }
};