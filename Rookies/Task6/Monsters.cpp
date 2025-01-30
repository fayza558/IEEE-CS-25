#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<int>> monster_dist, player_dist;
vector<vector<pair<int, int>>> parent;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

void bfs_monsters(queue<pair<int, int>>& q) {
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] == '.' && monster_dist[nx][ny] == -1) {
                monster_dist[nx][ny] = monster_dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool bfs_player(int start_x, int start_y, pair<int, int>& exit_point) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    player_dist[start_x][start_y] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
            exit_point = {x, y};
            return true;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] == '.' && player_dist[nx][ny] == -1 &&
                (monster_dist[nx][ny] == -1 || player_dist[x][y] + 1 < monster_dist[nx][ny])) {

                player_dist[nx][ny] = player_dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    monster_dist.assign(n, vector<int>(m, -1));
    player_dist.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> monster_queue;
    int start_x, start_y;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monster_queue.push({i, j});
                monster_dist[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start_x = i;
                start_y = j;
            }
        }
    }

    bfs_monsters(monster_queue);

    pair<int, int> exit_point;
    if (bfs_player(start_x, start_y, exit_point)) {
        cout << "YES\n";

        string path;
        int x = exit_point.first, y = exit_point.second;
        while (make_pair(x, y) != make_pair(start_x, start_y)) {
            auto [px, py] = parent[x][y];
            for (int d = 0; d < 4; d++) {
                if (px + dx[d] == x && py + dy[d] == y) {
                    path += dir[d];
                    break;
                }
            }
            x = px, y = py;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n" << path << "\n";
    } else {
        cout << "NO\n";
    }
}
