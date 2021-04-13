/*
Group Points

You are given a two-dimensional list of integers points and an integer k. Each list in points is of the form (x, y) representing Cartesian coordinates. Assuming you can group any point a and b if the Euclidean distance between them is ≤ k, return the total number of disjoint groups.

Note that if points a and b are grouped and b and c are grouped, then a and c are in the same group.

Constraints

n ≤ 1,000 where n is length of points.
Example 1
Input
points = [
    [1, 1],
    [2, 2],
    [3, 3],
    [10, 10],
    [11, 11]
]
k = 2
Output
2
Explanation
There are two groups:

[1,1],[2,2],[3,3]
[10,10],[11,11]

This solution uses a data structure called 'UFDS' or Union-Find Disjoint Set to maintain connected components. Normal distance checking is done without square roots to avoid precision issues.

Complexity

Time: O(N^2)
Space: O(N)
*/
const int MXN = 1005;
int par[MXN];
int gr;

void setup(int n) {
    gr = n;
    for (int i = 0; i < n; i++) par[i] = i;
}

int parent(int a) {
    if (par[a] == a) return a;
    return par[a] = parent(par[a]);
}

void conn(int a, int b) {
    a = parent(a);
    b = parent(b);
    if (a == b) {
        return;
    }
    par[a] = b;
    gr--;
}

int dist(vector<int> a, vector<int> b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

int solve(vector<vector<int>>& points, int k) {
    setup(points.size());
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            if (dist(points[i], points[j]) <= k * k) {
                conn(i, j);
            }
        }
    }
    return gr;
}
