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
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef pair<pair<int, int>, char> COW;

bool cmp(const COW& c1, const COW& c2) {
    if (c1.first.second != c2.first.second)
        return c1.first.second < c2.first.second;
    else return c1.second < c2.second;
}

int main() {
    freopen("cowrect.in", "r", stdin);
    freopen("cowrect.out", "w", stdout);
    int N;
    scanf("%d", &N);
    vector<COW> cows;
    vector<int> holx;
    FOR(i, N) {
        int x, y;
        char kind;
        scanf("%d %d %c", &x, &y, &kind);
        cows.push_back(make_pair(make_pair(x, y), kind));
        if (kind == 'H') holx.push_back(x);
    }
    sort(holx.begin(), holx.end());
    int len = unique(holx.begin(), holx.end()) - holx.begin();
    holx.resize(len);
    // sort all cows in y ascending order
    sort(cows.begin(), cows.end(), cmp);
    int mx = 0, area = 0;
    // enumerate every pair of vertical lines
    for (int i = 0; i < holx.size(); ++i) {
        for (int j = i + 1; j < holx.size(); ++j) {
            int cnt = 0, cur = cows[0].first.second, prev = cur;
            int dx = holx[j] - holx[i];
            int pvg = INT_MIN / 2;
            // line sweep
            for (int k = 0; k < cows.size(); ++k) {
                int nx = cows[k].first.first, ny = cows[k].first.second;
                char kd = cows[k].second;
                if (nx < holx[i] || nx > holx[j]) continue;
                if (kd == 'G') {
                    // assert(cur >= prev);
                    if (cnt > mx || (cnt == mx && dx * (cur - prev) < area)) {
                        mx = cnt;
                        area = dx * (cur - prev);
                    }
                    cnt = 0; cur = prev = pvg = ny;
                }
                else {
                    if (ny == pvg) continue;
                    if (cnt == 0) prev = ny;
                    ++cnt; cur = ny;
                }
            }
            if (cnt > mx || (cnt == mx && dx * (cur - prev) < area)) {
                mx = cnt;
                area = dx * (cur - prev);
            }
        }
    }
    printf("%d\n%d\n", mx, area);
    return 0;
}
