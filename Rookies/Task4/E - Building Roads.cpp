#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    component.push_back(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                component.push_back(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> components;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> component;
            bfs(i, graph, visited, component);
            components.push_back(component);
        }
    }

    vector<pair<int, int>> new_roads;
    if (components.size() > 1) {
        for (int i = 1; i < components.size(); i++) {
            new_roads.push_back({components[i - 1][0], components[i][0]});
        }
    }

    cout << new_roads.size() << endl;
    for (auto& road : new_roads) {
        cout << road.first << " " << road.second << endl;
    }

    return 0;
}
