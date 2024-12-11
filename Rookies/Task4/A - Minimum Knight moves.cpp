#include <bits/stdc++.h>
using namespace std;

struct cell {
    int x, y, dis;
    cell() {}
    cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

bool isInside(int x, int y, int N) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

int bfs(int pos[], int target[], int N) {
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    queue<cell> q;
    q.push(cell(pos[0], pos[1], 0));
    bool vis[N + 1][N + 1];
    memset(vis, false, sizeof(vis));
    vis[pos[0]][pos[1]] = true;

    while (!q.empty()) {
        cell t = q.front();
        q.pop();

        if (t.x == target[0] && t.y == target[1]) {
            return t.dis;
        }

        for (int i = 0; i < 8; i++) {
            int x = t.x + dx[i];
            int y = t.y + dy[i];
            if (isInside(x, y, N) && !vis[x][y]) {
                vis[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string start, destination;
        cin >> start >> destination;

        int pos[2] = {start[1] - '0', start[0] - 'a' + 1};
        int target[2] = {destination[1] - '0', destination[0] - 'a' + 1};

        cout << bfs(pos, target, 8) << endl;
    }
    return 0;
}
