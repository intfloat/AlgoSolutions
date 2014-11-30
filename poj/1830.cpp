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

int K, N, eq[35][35];

int gaussian() {
    int cnt = 0;
    FOR(i, N) {
        int pos = 0;
        for (pos = i; pos < N; ++pos) {
            if (eq[pos][i]) break;
        }
        if (pos < N) {
            ++cnt;
            FOR(j, N + 1) swap(eq[i][j], eq[pos][j]);
            FOR(j, N) {
                if (i == j || eq[j][i] == 0) continue;
                FOR(k, N + 1) eq[j][k] ^= eq[pos][k];
            }
        }
    }
    FOR(i, N) {
        if (eq[i][i] == 0 && eq[i][N]) {
            return -1;
        }
    }
    return 1 << (N - cnt);
}

int main() {
    cin >> K;
    while (K--) {
        cin >> N;
        memset(eq, 0, sizeof(eq));
        FOR(i, N) { cin >> eq[i][N]; eq[i][i] = 1; }
        FOR(i, N) { int t; cin >> t; eq[i][N] ^= t; }
        int x, y;
        while (cin >> x >> y) {
            if (x == 0 && y == 0) break;
            --x; --y;
            eq[y][x] = 1;
        }
        int res = gaussian();
        if (res < 0) cout << "Oh,it's impossible~!!" << endl;
        else cout << res << endl;
    }
    return 0;
}
