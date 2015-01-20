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
using namespace std;

const int off = 500;
const int MAX_N = 1005;
int dp[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
set<pair<int, int> > s;

const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};

int main() {
    int x, y, n;
    scanf("%d%d%d", &x, &y, &n);
    pair<int, int> t = make_pair(x, y);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        s.insert(make_pair(a, b));
    }
    memset(visited, false, sizeof(visited));
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0 + off][0 + off] = true;
    dp[0 + off][0 + off] = 0;
    while (!q.empty()) {
        pair<int, int> tp = q.front(); q.pop();     
        for (int i = 0; i < 4; ++i) {
            int xx = tp.first + dir_x[i];
            int yy = tp.second + dir_y[i];
            if (xx < -off || xx > off || yy < -off || yy > off) continue;
            if (visited[xx + off][yy + off]) continue;
            if (s.find(make_pair(xx, yy)) != s.end()) continue;
            dp[xx + off][yy + off] = dp[tp.first + off][tp.second + off] + 1;
            visited[xx + off][yy + off] = true;
            q.push(make_pair(xx, yy));
            if (xx == x && yy == y) { printf("%d\n", dp[x + off][y + off]); return 0; }
        }
    }
    printf("%d\n", dp[x + off][y + off]);
    return 0;
}
