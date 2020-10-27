/*
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

Example 1 :

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

Example 2:

Input : arr = [2, 4, 1, 3], k = 4
Output: False
Explanation: There is no possible solution.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function canPair() which takes array and k as input parameter and returns true if 
array can be divided into pairs such that sum of every pair is divisible by k otherwise returns false.
 

Expected Time Complexity: O(n)
Expected Space Complexity : O(n)
 

Constraints:
1 <= length of array <= 100000
1 <= elements of array <= 100000
1 <= k <= 100000
*/
class Solution{
	public:
	bool canPair(vector<int>nums, int k){
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
                m[nums[i]%k]++;
        }
        for(auto x:m){
            if (x.first == 0) 
             {
             if (m[x.first] %2!=0)
                return false;
            }
            else if (2*x.first==k)
            {
                if (m[x.first] % 2 != 0)
                return false;
            }else if (m[x.first]!=m[k-x.first])
            {
                return false;
            } 

        }
        return true;

    }
};
