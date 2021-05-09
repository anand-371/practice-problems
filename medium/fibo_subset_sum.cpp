/*
Fibonacci Subset Sum
Given an integer n, return the minimum number of Fibonacci numbers required to sum up to n.

Constraints

1 ≤ n < 2 ** 31
Example 1
Input
n = 9
Output
2
Explanation
We can use the Fibonacci numbers [1, 8] to sum to 9.
*/
int solve(int n) {
    std::vector<int>fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    fibo.push_back(1);
    int i=3;
    while(true){
        int temp=fibo[i-1]+fibo[i-2];
        if (temp>n)
        {
            break;
        }
        fibo.push_back(temp);
        i++;
    }
    int j=fibo.size()-1;
    int count=0;
    while(n>0){
        count+=(n/fibo[j]);
        n=n%fibo[j];
        j--;   
    }
    return count;
}
