
#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
using namespace std;

int solve(int n, int m, const vector<tuple<int, int, int>>& cows,
          const vector<tuple<int, int, int, int>>& conditioners,
          int index, vector<int>& cooling) {
    if (index == m) {
        for (int i = 0; i < cows.size(); ++i) {
            int s = get<0>(cows[i]);
            int t = get<1>(cows[i]);
            int c = get<2>(cows[i]);
            for (int stall = s; stall <= t; ++stall) {
                if (cooling[stall] < c) {
                    return INT_MAX;
                }
            }
        }
        return 0;
    }

    int a = get<0>(conditioners[index]);
    int b = get<1>(conditioners[index]);
    int p = get<2>(conditioners[index]);
    int cost = get<3>(conditioners[index]);

    int cost_skip = solve(n, m, cows, conditioners, index + 1, cooling);

    vector<int> new_cooling = cooling;
    for (int stall = a; stall <= b; ++stall) {
        new_cooling[stall] += p;
    }
    int cost_use = solve(n, m, cows, conditioners, index + 1, new_cooling);
    if (cost_use != INT_MAX) {
        cost_use += cost;
    }

    return min(cost_skip, cost_use);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> cows(n);
    for (int i = 0; i < n; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        cows[i] = make_tuple(s, t, c);
    }
    vector<tuple<int, int, int, int>> conditioners(m);
    for (int i = 0; i < m; ++i) {
        int a, b, p, cost;
        cin >> a >> b >> p >> cost;
        conditioners[i] = make_tuple(a, b, p, cost);
    }
    vector<int> cooling(101, 0);
    int result = solve(n, m, cows, conditioners, 0, cooling);
    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}

