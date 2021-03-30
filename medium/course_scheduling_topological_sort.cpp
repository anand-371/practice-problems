/*
Course Scheduling

You are given a two-dimensional integer list courses representing an adjacency list where courses[i] is the list of prerequisite courses needed to take course i.

Return whether it's possible to take all courses.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix.
Example 1
Input
Visualize
courses = [
    [1],
    [],
    [0]
]
Output
true
Explanation
We can take course 1, then course 0, and then course 2


*/
bool solve(vector<vector<int>>& courses) {
    std::vector<int>degree(courses.size(),0);
    for (int i = 0; i <courses.size(); ++i)
    {
            for(auto j:courses[i]){
                degree[j]++;
            }
    }
    int num_courses=courses.size();
    for (int i = 0; i < num_courses; ++i)
    {
        int j=0;
        for (; j<num_courses ; ++j)
        {
            if (degree[j]==0)
            {
                break;
            }
        }
        if (j==num_courses)
        {
            return false;
        }
        degree[j]--;
        for(auto v:courses[j]){
            degree[v]--;
        }
    }
    return true;
}
