#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

vector<string> g;
bool row[9][10], col[9][10], unit[9][10];
bool ok;

void solve(int pos) {
    if (pos >= 81) {
        ok = true;
        return;
    }
    int r = pos / 9, c = pos % 9, u = (r / 3) * 3 + c / 3;
    if (g[r][c] != '0') { solve(pos + 1); return; }
    for (int i = 1; i <= 9; ++i) {
        if (row[r][i] || col[c][i] || unit[u][i]) continue;
        g[r][c] = '0' + i;
        row[r][i] = col[c][i] = unit[u][i] = true;
        solve(pos + 1);
        if (ok) return;
        row[r][i] = col[c][i] = unit[u][i] = false;
        g[r][c] = '0';
    }
    return;
}

int main() {
    int T;
    cin >> T;
    g.resize(9);
    FOR(tt, T) {
        FOR(i, 9) cin >> g[i];
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(unit, false, sizeof(unit));
        ok = false;
        FOR(i, 9) FOR(j, 9) {
            if (g[i][j] != '0') {
                int ch = g[i][j] - '0';
                int u = 3 * (i / 3) + j / 3;
                row[i][ch] = col[j][ch] = unit[u][ch] = true;
            }
        }
        solve(0);
        FOR(i, 9) cout << g[i] << endl;
    }
    return 0;
}
