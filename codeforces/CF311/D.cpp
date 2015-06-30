#include <bits/stdc++.h>
#define EMPTY -1
#define WHITE 0
#define BLACK 1
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
vector<vector<int> > g;
vector<int> color;
bool bi = true;
ll wh, bk, two = 0;
void dfs(int idx, int val) {
    if (!bi) return;
    color[idx] = val;
    if (val == WHITE) ++wh;
    else if (val == BLACK) ++bk;
    FOR(i, g[idx].size()) {
        int to = g[idx][i];
        if (color[to] == EMPTY) {
            dfs(to, !val);
        }
        else if (color[to] == val) {
            bi = false;
            return;
        }
    }
}
int main() {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    g.resize(n);
    color.resize(n);
    fill(color.begin(), color.end(), EMPTY);
    FOR(i, n) g[i].clear();
    FOR(i, m) {
        scanf("%d %d", &x, &y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll res = 0;
    FOR(i, n) {
        if (color[i] == EMPTY) {
            wh = bk = 0;
            dfs(i, WHITE);
            if (!bi) {
                cout << "0 1" << endl;
                return 0;
            }
            if (wh >= 2) {
                res += wh * (wh - 1) / 2;
            }
            if (bk >= 2) {
                res += bk * (bk - 1) / 2;
            }
            if (wh == 1 && bk == 1) {
                ++two;
            }
        }
    }
    if (res > 0) {
        cout << 1 << " " << res << endl;
    }
    else if (two > 0) {
        cout << 2 << " " << (long long)m * (n - 2ll) << endl;
    }
    else {
        res = (ll)n * (n - 1ll) * (n - 2ll) / 6ll;
        cout << 3 << " " << res << endl;
    }
    return 0;
}
