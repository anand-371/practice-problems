/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return intervals;
        }
        sort(intervals.begin(),intervals.end(),[](vector<int>&A,vector<int>&B){
            return A[0] < B[0];
        });
        stack<vector<int>>st;
        st.push(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            std::vector<int> temp=st.top();
            st.pop();
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            cout<<temp[0]<<" "<<temp[1]<<endl;
            if (intervals[i][0]<=temp[1])
            {
                temp[1]=std::max(intervals[i][1],temp[1]);
                st.push(temp);
            }else{
                st.push(temp);
                st.push(intervals[i]);
            }
        }
        std::vector<vector<int>> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        std::reverse(result.begin(),result.end());
        return result;
    }
};
