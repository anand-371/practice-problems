/*
Detect cycle in a directed graph
Your task:
You don’t need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
	bool dfs_util(vector<int>adj[],int i,vector<bool>&visited,vector<bool>&rec_stack){
    if (visited[i]==false)
    {
        visited[i]=true;
        rec_stack[i]=true;

        for(auto x: adj[i]){
            if (visited[x]==false && dfs_util(adj,x,visited,rec_stack))
            {
                return true;
            }else if (rec_stack[x]==true)
            {
                return true;
            }
        }
    }        
        rec_stack[i]=false;
        return false;
    
}

bool isCyclic(int V, vector<int> adj[]) {
        std::vector<bool> visited(V,false);
        std::vector<bool> rec_stack(V,false);
        for (int i = 0; i < V; ++i)
        {
            if(dfs_util(adj,i,visited,rec_stack)){
                return true;
            }
        }
        return false;

    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends