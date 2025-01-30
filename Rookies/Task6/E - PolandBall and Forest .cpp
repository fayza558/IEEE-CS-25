#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p != i) {
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
    }

    int treeCount = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            treeCount++;
            dfs(i);
        }
    }

    cout << treeCount << endl;
    return 0;
}
