#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000005;
const int MAX_M = MAX_N * 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], wei[MAX_M], ptr;
int n, m, s, t;
inline void addedge(int x, int y, int w) {
    pnt[ptr] = y; nt[ptr] = head[x]; wei[ptr] = w; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; wei[ptr] = w; head[y] = ptr++;
}
inline bool check(int up) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        for (int i = head[tp]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (visited[to] || wei[i] == -1 || wei[i] >= up) {
                continue;
            }
            if (to == t) return true;
            visited[to] = true;
            q.push(to);
        }
    }
    return false;
}
int main() {
    int x, y, w;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &t);
    ptr = 0;
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &w);
        addedge(x, y, w);
    }
    int res = 0;
    for (int i = 30; i >= 0; --i) {
        int val = (1 << i);
        if (check(val)) {
            for (int j = 0; j < ptr; ++j) {
                if (wei[j] >= val) {
                    wei[j] = -1;
                }
            }
        }
        else {
            res += val;
            for (int j = 0; j < ptr; ++j) {
                if (wei[j] >= val) {
                    wei[j] -= val;
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
