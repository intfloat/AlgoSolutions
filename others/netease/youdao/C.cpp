#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool used[105][105];
int cx, cy, dis, k;
int get(int r, int c, int num) {
    int ret = 0;
    for (int i = c; i < c + num; ++i) {
        if (used[r][i]) return INT_MAX;
        else ret += abs(cx - r) + abs(cy - i);
    }
    return ret;
}
int solve(int r, int num) {
    dis = INT_MAX;
    int ret = -1;
    for (int i = 1; i + num - 1 <= k; ++i) {
        int cur = get(r, i, num);
        if (cur < dis) {
            dis = cur;
            ret = i;
        }
    }
    return ret;
}
int main() {
    int q;
    while (cin >> q >> k) {
        FOR(i, k) FOR(j, k) used[i + 1][j + 1] = false;
        cx = (k + 1) / 2; cy = (k + 1) / 2;
        FOR(i, q) {
            int t;
            cin >> t;
            int rr = -1, rc = -1, mn = INT_MAX;
            for (int j = 1; j <= k; ++j) {
                int pos = solve(j, t);
                if (pos >= 1 && dis < mn) {
                    mn = dis;
                    rr = j;
                    rc = pos;
                }
            }
            if (rr > 0) {
                cout << rr << " " << rc << " " << rc + t - 1 << endl;
                FOR(j, t) used[rr][rc + j] = true;
            }
            else cout << -1 << endl;
        }
    }
    return 0;
}
