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
#define LIGHT 374834 // just a random number...
#define EMPTY 987662 // another random number...
using namespace std;

int cnt[10][10], g[10][10], row, col, mn;
bool ok;
const int dir_x[] = {-1, 1, 0, 0};
const int dir_y[] = {0, 0, 1, -1};

bool check() {
    FOR(i, row) FOR(j, col) {
        if (g[i][j] == EMPTY && cnt[i][j] == 0) return false;
        if (g[i][j] >= 0 && g[i][j] <= 4) {
            int cur = 0;
            FOR(k, 4) {
                int nr = i + dir_x[k], nc = j + dir_y[k];
                cur += (nr >= 0 && nr < row && nc >= 0 && nc < col && g[nr][nc] == LIGHT);
            }
            if (cur != g[i][j]) return false;
        }
    }
    return true;
}

void solve(int pos, int num) {
    if (num >= mn) return; // can not be optimal solution
    if (pos >= row * col) {
        // check();
        if (check()) mn = min(mn, num);
        return;
    }
    int r = pos / col, c = pos % col;
    if (g[r][c] >= -1 && g[r][c] <= 4 && r > 0 && cnt[r - 1][c] == 0 && g[r - 1][c] == EMPTY) return;
    if (cnt[r][c] > 0 || g[r][c] != EMPTY) {
        solve(pos + 1, num);
        return;
    }
    // do nothing
    solve(pos + 1, num);

    // put a light here
    g[r][c] = LIGHT; cnt[r][c] = 1;
    assert(cnt[r][c] == 1);
    FOR(i, 4) {
        int nr = r + dir_x[i], nc = c + dir_y[i];
        while (nr >= 0 && nr < row && nc >= 0 && nc < col && g[nr][nc] == EMPTY) {
            ++cnt[nr][nc];
            nr += dir_x[i]; nc += dir_y[i];
        }
    }
    solve(pos + 1, num + 1);
    FOR(i, 4) {
        int nr = r + dir_x[i], nc = c + dir_y[i];
        while (nr >= 0 && nr < row && nc >= 0 && nc < col && g[nr][nc] == EMPTY) {
            assert(cnt[nr][nc] > 0);
            --cnt[nr][nc];
            nr += dir_x[i]; nc += dir_y[i];
        }
    }
    g[r][c] = EMPTY; --cnt[r][c];
    assert(cnt[r][c] == 0);
    return;
}

int main() {
    int x, y, c, block;
    // clock_t start = clock();
    while (cin >> row >> col) {
        if (row == 0 && col == 0) break;
        cin >> block;
        FOR(i, 10) FOR(j, 10) { cnt[i][j] = 0; g[i][j] = EMPTY; }
        FOR(i, block) {
            cin >> x >> y >> c;
            --x; --y;
            g[x][y] = c;
        }
        mn = 100;
        solve(0, 0);
        if (mn < 100) cout << mn << endl;
        else cout << "No solution" << endl;
    }
    // cout << "time used: " << clock() - start << endl;
    return 0;
}
