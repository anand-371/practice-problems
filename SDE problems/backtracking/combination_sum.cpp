/*
Combination Sum

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example,
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]
*/

void back_track(vector<int>A,int sum,int B,vector<int>temp,vector<vector<int>>&result,int idx){
    if (sum==B)
    {
        result.push_back(temp);
        return;
    }
    else if (B<sum)
    {
        return;
    }else{
        for (int i = idx; i < A.size(); ++i)
        {
            if(i==0||(i>0 && A[i-1]!=A[i])){
            temp.push_back(A[i]);
            back_track(A,sum+A[i],B,temp,result,i);
            temp.pop_back();
            }
        }
    }
    return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int n=A.size();
    sort(A.begin(),A.end());
    std::vector<vector<int>>result;
    std::vector<int>temp;
    back_track(A,0,B,temp,result,0);
    return result;
}
