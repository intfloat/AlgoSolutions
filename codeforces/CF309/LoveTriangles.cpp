#include <stdio.h>
#include <string.h>
#include <iostream>
#define WHITE 0
#define BLACK 1
#define EMPTY -1
using namespace std;
const long long MOD = 1000000007;
const int MAX_N = 200005;
int head[MAX_N], pnt[MAX_N], type[MAX_N], nt[MAX_N], st[MAX_N];
bool visited[MAX_N];
int ptr = 0, n, m, x, y, t;
void addedge(int from, int to, int t) {
    pnt[ptr] = to; nt[ptr] = head[from]; type[ptr] = t; head[from] = ptr++;
    pnt[ptr] = from; nt[ptr] = head[to]; type[ptr] = t; head[to] = ptr++;
}
bool ok;
void dfs(int v, int status) {
    // cout << "VISIT: " << v + 1 << endl;
    visited[v] = true;
    st[v] = status;
    for (int i = head[v]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (!visited[to]) {
            if (type[i] == 0) {
                dfs(to, !status);
            }
            else {
                dfs(to, status);
            }
        }
        else if (type[i] == 1 && st[to] != st[v]) {
            ok = false;
        }
        else if (type[i] == 0 && st[to] == st[v]) {
            ok = false;
        }
        if (!ok) return;
    }
    return;
}
int main() {
    ok = true;
    scanf("%d %d", &n, &m);
    memset(head, -1, sizeof head);
    memset(visited, false, sizeof visited);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &t);
        --x; --y;
        addedge(x, y, t);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++cnt;
            dfs(i, 0);
        }
        if (!ok) {
            break;
        }
    }
    long long res = 1;
    for (int i = 1; i <= cnt - 1; ++i) {
        res = (res * 2ll) % MOD;
    }
    if (ok) {
        cout << res << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
