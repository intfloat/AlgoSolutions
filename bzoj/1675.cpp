/**************************************************************
    Problem: 1675
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:1320 ms
    Memory:1276 kb
****************************************************************/

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
#define FOR(i, begin, end) for (i = begin; i < end; ++i)
using namespace std;

int p[8], res = 0;
string g[5];
set<pair<int, int> > s;

const int dir_x[] = {0, 0, -1, 1};
const int dir_y[] = {-1, 1, 0, 0};
void preprocess() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 4; ++k) {
                int ni = i + dir_x[k], nj = j + dir_y[k];
                if (ni < 0 || nj < 0 || ni >= 5 || nj >= 5) continue;
                s.insert(make_pair(i * 5 + j, ni * 5 + nj));
            }
        }
    }
    return;
}

bool check() {
    bool visited[8];
    memset(visited, false, sizeof(visited));
    visited[1] = true;
    queue<int> q; q.push(1);
    int cnt = 1;
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        for (int i = 2; i < 8; ++i) {
            if (!visited[i] && s.find(make_pair(p[i], p[tp])) != s.end()) {
                visited[i] = true;
                q.push(i); ++cnt;
                if (cnt == 7) return true;
            }
        }
    }
    return false;
}

int main() {
    preprocess();
    for (int i = 0; i < 5; ++i) cin >> g[i];
    FOR(p[1], 0, 25) FOR(p[2], p[1] + 1, 25) FOR(p[3], p[2] + 1, 25)
    FOR(p[4], p[3] + 1, 25) FOR(p[5], p[4] + 1, 25) FOR(p[6], p[5] + 1, 25)
    FOR(p[7], p[6] + 1, 25) {
        int cnt = 0;
        for (int i = 1; i < 8; ++i) cnt += (g[p[i] / 5][p[i] % 5] == 'J');
        if (cnt < 4) continue;
        res += check();
    }
    cout << res << endl;
    return 0;
}
