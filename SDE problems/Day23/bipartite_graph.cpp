/*
Bipartite Graph 
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency 
list of graph and returns a boolean value true if graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V)
Expected Space Complexity: O(V)

*/

bool bfs(int u, vector<int> &color, vector<int> adj[]) {
  queue<int> q;
  q.push(u);
  color[u] = 1;

  while(!q.empty()) {
  int i = q.front(); q.pop();
  for(auto x : adj[i]) {
  if(color[x] == 0) {
  color[x] = -color[i];
  q.push(x);
  }
  else if(color[x] == color[i])
  return false;
  }
  }

  return true;
}

bool isBipartite(int V, vector<int>adj[]){
  vector<int> color(V);

  for(int i = 0; i < V; i++) {
  if(!color[i] and !bfs(i, color, adj))
  return false;
  }
  return true;
}
