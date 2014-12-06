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

const int MAX_N = 305;
int eq[MAX_N][MAX_N], ans[MAX_N], n, m;
const string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int get_day(string s) {
    FOR(i, 7) if (s == days[i]) return i;
    // assert(false);
    return -1;
}

bool gaussian() {
    int cnt = 0;
    for (int i = 0; i < n && cnt < m; ++i) {
        int pos = -1;
        for (int j = cnt; j < m; ++j) {
            if (eq[j][i] != 0) { pos = j; break; }
        }
        if (pos < 0) continue;
        FOR(j, n + 1) swap(eq[cnt][j], eq[pos][j]);
        FOR(j, m) {
            if (cnt == j || eq[j][i] == 0) continue;
            int tmp = eq[j][i];
            FOR(k, n + 1) {
                eq[j][k] = (-eq[cnt][k] * tmp + eq[j][k] * eq[cnt][i]);
                eq[j][k] = (eq[j][k] % 7 + 7) % 7;
            }
        }
        ++cnt;
    }
    for (int i = cnt; i < m; ++i) {
        if (eq[i][n] != 0) {
            printf("Inconsistent data.\n");
            return false;
        }
    }
    if (cnt < n) { printf("Multiple solutions.\n"); return false; }
    FOR(i, n) {
        // assert(eq[i][i] != 0);
        if (eq[i][i] == 0) continue;
        while (eq[i][n] % eq[i][i] != 0) eq[i][n] += 7;
        ans[i] = eq[i][n] / eq[i][i];
        if (ans[i] < 3) ans[i] += 7;
    }
    return true;
}

int main() {
    int total, index;
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break;
        memset(eq, 0, sizeof(eq));
        FOR(i, m) {
            string s, t;
            scanf("%d", &total);
            cin >> s >> t;
            eq[i][n] = (get_day(t) - get_day(s) + 7 + 1) % 7;
            FOR(j, total) {
                scanf("%d", &index);
                eq[i][index - 1] = (eq[i][index - 1] + 1) % 7;
            }
        }
        if (gaussian()) {
            printf("%d", ans[0]);
            for (int i = 1; i < n; ++i) printf(" %d", ans[i]);
            printf("\n");
        }
    }
    return 0;
}
