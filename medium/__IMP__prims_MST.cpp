/*
Commutable Islands
There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Input Format:

The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
Output Format:

Return an integer representing the minimal cost required.
Constraints:

1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3
Examples:

Input 1:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 4]
            [1, 4, 3]
            [4, 3, 2]
            [1, 3, 10]  ]

Output 1:
    6

Explanation 1:
    We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

Input 2:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 2]
            [3, 4, 4]
            [1, 4, 3]   ]

Output 2:
    6

Explanation 2:
    We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred 
*/
int Solution::solve(int A, vector<vector<int> > &B) {
using PII = pair<int,int>;
vector<vector<PII>> adj(A+1);
for(auto edge:B){
    int weight = edge[2], u = edge[0], v = edge[1];
    adj[v].push_back({u,weight});
    adj[u].push_back({v,weight});
}
priority_queue<PII,vector<PII>,greater<PII>> q;
vector<bool> visited(A+1,false);
q.push({0,1}); 
int cost = 0;
while(!q.empty()){
    PII ele = q.top();
    q.pop();
    int u = ele.second;
    int weight = ele.first;
    if(!visited[u]){
        cost += weight;
        visited[u] = true;
        for(auto v: adj[u]){
            if(!visited[v.first]){
                q.push({v.second , v.first });
            }
        }
    }
}
return cost;
}
