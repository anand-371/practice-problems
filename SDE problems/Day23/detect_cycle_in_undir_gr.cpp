/*
Detect cycle in an undirected graph
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input 
parameters and returns a boolean value denoting if the undirected graph contains any cycle or not.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
 

Constraints:
1 ≤ V, E ≤ 105
*/
bool dfs_util(vector<int>adj[],int i,int parent,vector<bool>&visited){
    visited[i]=true;
    for(auto x:adj[i]){
        if (visited[x]==fasle)
        {   if (dfs_util(adj,x,i,visited))
            {
                return true;
            }
        }else if (x!=parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int>adj[]){
        std::vector<bool> visited(V,false);
        for (int i = 0; i < V; ++i)
        {
                if (visited[i]==false && dfs_util(adj,i,-1,visited))
                {
                    return true;
                }
        }
        return false;
    }
