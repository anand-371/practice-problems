/*
Cut Rods for Profit

You are given a list of integers rod_lens, where each element represents the length of a rod. You are also given integers profit_per_len and cost_per_cut.
You make profit_per_len profit per unit length of a rod but you can only sell rods that are all of the same length. You can also cut a rod into two integer 
pieces but each cut costs cost_per_cut. You can cut a rod as many times as you want. Return the maximum profit that can be made.

Constraints

n ≤ 1,000 where n is the length of rod_lens
m ≤ 1,000 where m is the maximum value in rod_lens
Example 1
Input
rod_lens = [5, 8]
profit_per_len = 6
cost_per_cut = 4
Output
64
Explanation
We can cut the rod of length 5 into two rods, one with length 4 and the other 1. We can then cut the rod of length 8 into two rods, both with length 4. 
Then we can sell all 3 rods of length 4 for a total profit of (4 + 4 + 4) * 6 - 8.

Example 2
Input
rod_lens = [5, 1]
profit_per_len = 1
cost_per_cut = 100
Output
5
Explanation
Since the cost to cut is too expensive, we just sell the rod with length 5.
*/
int solve(vector<int>& rod_lens, int profit_per_len, int cost_per_cut) {
    if(rod_lens.size()==0){return 0;}
    int max=*max_element(rod_lens.begin(),rod_lens.end());
    int cost=0;
    int max_profit=0;
    for (int i = 1; i <=max; ++i)
     {
        int num_cuts=0;
        int temp=0;
        int num_parts=0;
        for (int j = 0; j < rod_lens.size(); ++j)
        {
            if(rod_lens[j]<i){continue;}
            num_parts=rod_lens[j]/i;
            num_cuts=(rod_lens[j]+i-1)/(i)-1;
            temp+=std::max(0,num_parts*i*profit_per_len-num_cuts*cost_per_cut);   
        }
        cout<<cost<<endl;
        max_profit=std::max(max_profit,temp);
     } 
     return max_profit;
}
