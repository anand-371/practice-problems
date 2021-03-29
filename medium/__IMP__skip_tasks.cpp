/*
Skip Tasks to Minimize Work
You are given a list of integers nums representing tasks that you must get through in order. Each value represents the amount of time it takes to finish that task. Given that you can skip tasks as long as you don’t skip twice in a row, return the minimum time it takes to get through all the tasks.

Constraints

n ≤ 100,000 where n is the length of nums.
Example 1
Input
nums = [10, 5, 7, 15]
Output
12
Explanation
We can skip the first and last tasks.

Example 2
Input
nums = [10, 20]
Output
10
Explanation
We can skip the last task.
*/
int solve(vector<int>& nums) {
    if(nums.size()==0){return 0;}
    int n=nums.size();
    std::vector<int>incl(n,0);
    std::vector<int>excl(n,0);
    incl[0]=nums[0];
    excl[0]=0;
    for (int i = 1; i < n; ++i)
    {
            incl[i]=std::min(incl[i-1],excl[i-1])+nums[i];
            excl[i]=incl[i-1];
    }
    return std::min(incl[n-1],excl[n-1]);
}
