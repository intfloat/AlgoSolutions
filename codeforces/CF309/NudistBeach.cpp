#include <bits/stdc++.h>
using namespace std;
vector<int> tcnt, cnt, cur, res, degree;
vector<bool> visited, inv;
int n, m, k, x, y;
int ptr = 0;
const int MAX_N = 200005;
int pnt[MAX_N], head[MAX_N], nt[MAX_N];
bool check(double mid) {
    inv.resize(n);
    fill(inv.begin(), inv.end(), false);
    queue<int> q;
    tcnt = cnt;
    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            inv[i] = true;
        }
        else if (1.0 * tcnt[i] / degree[i] < mid) {
            inv[i] = true;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        for (int i = head[tp]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (inv[to]) continue;
            --tcnt[to];
            if (1.0 * tcnt[to] / degree[to] < mid) {
                inv[to] = true;
                q.push(to);
            }
        }
    }
    cur.clear();
    for (int i = 0; i < n; ++i) {
        if (!inv[i]) {
            cur.push_back(i);
        }
    }
    return cur.size() > 0;
}
void addedge(int from, int to) {
    pnt[ptr] = to; nt[ptr] = head[from]; head[from] = ptr++;
    pnt[ptr] = from; nt[ptr] = head[to]; head[to] = ptr++;
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    memset(head, -1, sizeof head);
    visited.resize(n);
    degree.resize(n);
    cnt.resize(n);
    fill(visited.begin(), visited.end(), false);
    fill(degree.begin(), degree.end(), 0);
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        visited[x - 1] = true;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        --x; --y;
        addedge(x, y);
        ++degree[x];
        ++degree[y];
        if (!visited[x]) ++cnt[y];
        if (!visited[y]) ++cnt[x];
    }
    double left = 0, right = 1;
    int cc = 0;
    while (left + 1e-10 < right && ++cc < 500) {
        double mid = (left + right) / 2;
        if (check(mid)) {
            res = cur;
            left = mid;
        }
        else {
            right = mid;
        }
    }
    if (res.empty()) {
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                res.push_back(i);
            }
        }
    }
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); ++i) {
        printf("%d ", res[i] + 1);
    }
    printf("\n");
    return 0;
}
