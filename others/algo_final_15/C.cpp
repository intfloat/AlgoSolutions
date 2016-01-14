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
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1005;
vector<int> g[MAX_N];
int n, m, match[MAX_N];
bool visited[MAX_N];
bool dfs(int pos) {
    FOR(i, g[pos].size()) {
        int to = g[pos][i];
        if (visited[to]) continue;
        visited[to] = true;
        if (match[to] == -1 || dfs(match[to])) {
            match[to] = pos;
            return true;
        }
    }
    return false;
}
int main() {
    memset(match, -1, sizeof match);
    scanf("%d %d", &m, &n);
    int u, v;
    FOR(i, m) {
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].push_back(v + n);
    }
    int res = 0;
    FOR(i, n) {
        memset(visited, false, sizeof visited);
        res += dfs(i);
    }
    printf("%d\n", n - res);
    return 0;
}
