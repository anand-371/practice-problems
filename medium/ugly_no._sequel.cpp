/*
Ugly Number Sequel

Consider a sequence of sorted integers whose prime factors only include 2, 3 or 5. The first few terms are 1, 2, 3, 4, 5, 6, 8, 9, 10.

Given an integer n, return the nth (0-index) term of the sequence.

Constraints

0 ≤ n ≤ 100,000
Example 1
Input
n = 5
Output
6
Explanation
Since the first six terms are 1, 2, 3, 4, 5, 6.
*/
int solve(int n) {
    std::vector<int>result(1,1);
    int i=0;
    int j=0;
    int k=0;
    while(result.size()<=n){
        result.push_back(std::min(result[i]*2,std::min(result[j]*3,result[k]*5)));
        if (result.back()==result[i]*2)
        {
            i++;
        }
        if (result.back()==result[j]*3)
        {
            j++;
        }
        if (result.back()==result[k]*5)
        {
            k++;
        }
    }
    return result.back();
}
