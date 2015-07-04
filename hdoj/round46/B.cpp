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
typedef unsigned long long ll;
typedef pair<int, int> edge;
int n, m, x, y;
void solve() {
    vector<pair<int, int> > arr;
    FOR(i, n) {
        scanf("%d %d", &x, &y);
        arr.push_back(make_pair(x, y));
    }
    set<edge> st;
    vector<vector<int> > g(n + 1, vector<int>());
    FOR(i, m) {
        scanf("%d %d", &x, &y);
        if (x > y) swap(x, y);
        g[x].push_back(y);
        st.insert(make_pair(x, y));
    }
    if (m == 0) {
        printf("1 %d\n", n);
        return;
    }
    int cnt = 0, four = 0;
    for (int i = 1; i <= n; ++i) {
        FOR(j, g[i].size()) for (int k = j + 1; k < g[i].size(); ++k) {
            x = g[i][j]; y = g[i][k];
            if (x > y) swap(x, y);
            if (st.find(make_pair(x, y)) != st.end()) {
                ++cnt;
                for (int p = y; p < n; ++p) {
                    if (st.find(make_pair(i, p + 1)) == st.end()
                        && st.find(make_pair(p + 1, i)) == st.end()) continue;
                    if (st.find(make_pair(p + 1, x)) == st.end()
                        && st.find(make_pair(x, p + 1)) == st.end()) continue;
                    if (st.find(make_pair(p + 1, y)) == st.end()
                        && st.find(make_pair(y, p + 1)) == st.end()) continue;
                    ++four;
                }
            }
        }
    }
    if (four > 0) {
        printf("4 %d\n", four);
    }
    else if (cnt == 0) {
        printf("2 %d\n", m);
    }
    else {
        printf("3 %d\n", cnt);
    }
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        solve();
    }
    return 0;
}
