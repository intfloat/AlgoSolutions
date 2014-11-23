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

bool has_win(int d, bool first);
string g[4];
string t = "ox";
int rx, ry, cnt;

bool check(bool first) {
    FOR(i, 4) {
        int total = 0;
        FOR(j, 4) total += (g[i][j] == t[first]);
        if (total == 4) return true;
    }
    FOR(i, 4) {
        int total = 0;
        FOR(j, 4) total += (g[j][i] == t[first]);
        if (total == 4) return true;
    }
    int total = 0;
    FOR(i, 4) total += (g[i][i] == t[first]);
    if (total == 4) return true;
    total = 0;
    FOR(i, 4) total += (g[i][3 - i] == t[first]);
    if (total == 4) return true;
    return false;
}

bool all_lost(int d, bool first) {
    if (check(!first)) return true;
    if (check(first)) return false;
    if (cnt == 16) return false;
    FOR(i, 4) FOR(j, 4) {
        if (g[i][j] != '.') continue;
        g[i][j] = t[first]; ++cnt;
        bool ok = has_win(d + 1, !first);
        g[i][j] = '.'; --cnt;
        if (!ok) return false;
    }
    return true;
}

bool has_win(int d, bool first) {
    if (check(first)) return true;
    if (check(!first)) return false;
    if (cnt == 16) return false;
    FOR(i, 4) FOR(j, 4) {
        if (g[i][j] != '.') continue;
        g[i][j] = t[first]; ++cnt;
        bool ok = all_lost(d + 1, !first);
        g[i][j] = '.'; --cnt;
        if (ok && !d) { rx = i; ry = j; return true; }
        if (ok) return true;
    }
    return false;
}

int main() {
    string start;
    while (cin >> start && start == "?") {
        FOR(i, 4) cin >> g[i];
        cnt = 0;
        FOR(i, 4) FOR(j, 4) cnt += (g[i][j] != '.');
        if (cnt <= 4) { cout << "#####" << endl; continue; }
        if (has_win(0, true)) cout << "(" << rx << "," << ry << ")" << endl;
        else cout << "#####" << endl;
    }
    return 0;
}
