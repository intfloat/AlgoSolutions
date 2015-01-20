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
bool ok[30];
void preprocess() {
    memset(ok, false, sizeof(ok));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (g[i][j] == 'J') ok[i * 5 + j] = true;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dir_x[k], nj = j + dir_y[k];
                if (ni < 0 || nj < 0 || ni >= 5 || nj >= 5) continue;
                s.insert(make_pair(i * 5 + j, ni * 5 + nj));
            }
        }
    }
    return;
}

bool visited[8];
bool check() {  
    memset(visited, false, sizeof(visited));
    visited[1] = true;
    int q[10], h = 0, t = 0;
    q[t++] = 1;
    int cnt = 1;
    while (h < t) {
        int tp = q[h++];
        for (int i = 2; i < 8; ++i) {
            if (!visited[i] && s.find(make_pair(p[i], p[tp])) != s.end()) {
                visited[i] = true;
                q[t++] = i; ++cnt;
                if (cnt == 7) return true;
            }
        }
    }
    return false;
}

int main() {    
    for (int i = 0; i < 5; ++i) cin >> g[i];    
    preprocess();
    int t = 0;
    FOR(p[1], 0, 19) FOR(p[2], p[1] + 1, 20) FOR(p[3], p[2] + 1, 21)
    FOR(p[4], p[3] + 1, 22) FOR(p[5], p[4] + 1, 23) FOR(p[6], p[5] + 1, 24)
    FOR(p[7], p[6] + 1, 25) {
        int cnt = 0; ++t;
        for (int i = 1; i < 8; ++i) cnt += ok[p[i]];
        if (cnt < 4) continue;
        res += check();
    }
    cout << "total number: " << t << endl;
    cout << res << endl;
    return 0;
}
