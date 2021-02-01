/*

Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V
denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. 
As there are multiple Topological orders possible, you may return any of them.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2

*/
class Solution{
	public:
	void dfs_util(vector<int>adj[],int index,vector<bool>&visited,stack<int>&st){
    visited[index]=true;
    for (auto x: adj[index])
    {
        if (visited[x]==false)
        {
            dfs_util(adj,x,visited,st);
        }
    }

    st.push(index);
}

vector<int> topoSort(int V, vector<int> adj[]) {
        stack<int>st;
        std::vector<bool> visited(V,false);
        for (int i = 0; i < V; ++i)
        {
                if (visited[i]==false)
                {
                    dfs_util(adj,i,visited,st);
                }
        }
        std::vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};
