#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <utility>
#include <queue>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 20005;
const int MAX_M = MAX_N * 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], wei[MAX_M], ptr, n;
bool visited[MAX_N];
int tson[MAX_N], mson[MAX_N], root, mn;
ll res = 0;
inline void dfs(int pos, int fa) {
    tson[pos] = mson[pos] = 0;
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to == fa || visited[to]) continue;
        dfs(to, pos);
        tson[pos] += tson[to];
        mson[pos] = max(mson[pos], tson[to]);
    }
    ++tson[pos];
    mson[pos] = max(mson[pos], n - tson[pos]);
    if (mson[pos] < mn) {
        mn = mson[pos];
        root = pos;
    }
}
inline void addedge(int x, int y, int w) {
    pnt[ptr] = y; nt[ptr] = head[x]; wei[ptr] = w; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; wei[ptr] = w; head[y] = ptr++;
}
typedef pair<int, int> point;
inline void get_arr(vector<int>& dis, int pos) {
    dis.resize(3);
    dis[0] = dis[1] = dis[2] = 0;
    queue<point> q;
    q.push(make_pair(pos, 0));
    while (!q.empty()) {
        point tp = q.front(); q.pop();
        ++dis[tp.second % 3];
        for (int i = head[tp.first]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (tson[to] > tson[tp.first] || visited[to]) continue;
            q.push(make_pair(to, wei[i] + tp.second));
        }
    }
}
inline ll work(int pos, int base) {
    ll ret = 0;
    vector<int> arr;
    get_arr(arr, pos);
    if (base % 3 == 0) ret = arr[0] * arr[0] + arr[1] * arr[2] * 2;
    else if (base % 3 == 1) ret = arr[0] * arr[2] * 2 + arr[1] * arr[1];
    else ret = arr[0] * arr[1] * 2 + arr[2] * arr[2];
    return ret;
}
void solve(int pos) {
    mn = INT_MAX; root = -1;
    dfs(pos, -1); dfs(root, -1);
    res += work(root, 0);
    visited[root] = true;
    vector<int> son;
    for (int i = head[root]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (visited[to]) continue;
        son.push_back(tson[to]);
        res -= work(to, wei[i] * 2);
    }
    int cur = 0;
    for (int i = head[root]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (visited[to]) continue;
        n = son[cur++];
        solve(to);
    }
}
int main() {
    int x, y, w;
    ptr = 0;
    memset(head, -1, sizeof head);
    memset(visited, false, sizeof visited);
    scanf("%d", &n);
    ll total = n * n;
    FOR(i, n - 1) {
        scanf("%d %d %d", &x, &y, &w);
        --x; --y;
        addedge(x, y, w % 3);
    }
    solve(0);
    // printf("%lld\n", res);
    ll g = __gcd(total, res);
    total /= g; res /= g;
    printf("%lld/%lld\n", res, total);
    return 0;
}
