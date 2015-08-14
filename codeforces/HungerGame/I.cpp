#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 1005;
const int MAX_M = MAX_N * MAX_N;
int head[MAX_N], nt[MAX_M], pnt[MAX_M], wei[MAX_M], ptr;
inline void addedge(int x, int y, int w) {
    pnt[ptr] = y; nt[ptr] = head[x]; wei[ptr] = w; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; wei[ptr] = w; head[y] = ptr++;
}
int main() {
    int n, m, x, y, w;
    scanf("%d %d", &n, &m);
    memset(head, -1, sizeof head);
    ptr = 0;
    ll res = 0;
    FOR(i, m) {
        scanf("%d %d %d", &x, &y, &w);
        --x; --y;
        res += w;
        addedge(x, y, w);
    }
    bool visited[MAX_N];
    vector<int> dis(n, INT_MAX);
    dis[0] = 0;
    memset(visited, false, sizeof visited);
    for (int i = 0; i < n; ++i) {
        int mn = INT_MAX, pos = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dis[j] < mn) {
                mn = dis[j];
                pos = j;
            }
        }
        if (mn == INT_MAX) {
            cout << -1 << endl;
            return 0;
        }
        visited[pos] = true;
        res -= mn;
        for (int j = head[pos]; j != -1; j = nt[j]) {
            int to = pnt[j];
            dis[to] = min(dis[to], wei[j]);
        }
    }
    cout << res << endl;
    return 0;
}
