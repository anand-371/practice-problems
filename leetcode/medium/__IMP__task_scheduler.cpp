/*
Task Scheduler

You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. 
Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either
one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there
must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> char_map(26);
        for (int i = 0; i < tasks.size(); ++i)
        {
            char_map[tasks[i]-'A']++;
        }
        sort(char_map.begin(),char_map.end());
        int max_val=char_map[25]-1;
        int id_max=max_val*n;
        for (int i = 24; i >=0; i--)
        {
            id_max-=std::min(char_map[i],max_val);
        }
        if (id_max>0)
        {
            return id_max+tasks.size();
        }else{
            return tasks.size();
        }
    }
    
};
