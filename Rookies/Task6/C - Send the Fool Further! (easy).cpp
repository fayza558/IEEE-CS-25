#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int v, cost;
};

vector<vector<Edge>> adj;
vector<bool> visited;
int n;

int dfs(int node) {
    visited[node] = true;
    int maxCost = 0;
    for (const Edge& edge : adj[node]) {
        if (!visited[edge.v]) {
            int cost = dfs(edge.v) + edge.cost;
            maxCost = max(maxCost, cost);
        }
    }
    visited[node] = false;
    return maxCost;
}

int main() {
    cin >> n;
    adj.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    cout << dfs(0) << endl;
    return 0;
}
