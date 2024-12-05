#include <iostream>
using namespace std;

int n, k;

bool isOk(int v) {
    int x = v;
    while (v > 0) {
        v /= k;
        x += v;
    }
    return x >= n;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     cin >> n >> k;
    int l = 1;
    int r = n;
    int ans = n;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (isOk(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

