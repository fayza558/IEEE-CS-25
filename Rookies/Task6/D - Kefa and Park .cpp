#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> hasCat;
int n, m, result = 0;

void dfs(int node, int parent, int catCount, int maxCats) {
    if (hasCat[node])
        catCount++;
    else
        catCount = 0;

    if (catCount > maxCats) return;

    bool isLeaf = true;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            isLeaf = false;
            dfs(neighbor, node, catCount, maxCats);
        }
    }

    if (isLeaf) result++;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    hasCat.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> hasCat[i];

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1, 0, m);
    cout << result << endl;

    return 0;
}
