#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10005;
const int MAX_M = MAX_N * 2;
int head[MAX_N], nt[MAX_M], pnt[MAX_M], ptr = 0;
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
int main() {
    int N, M, x, y;
    scanf("%d %d", &N, &M);
    if (M + 1 != N) {
        printf("NO\n");
        return 0;
    }
    memset(head, -1, sizeof head);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &x, &y);
        addedge(x, y);
    }
    queue<int> q;
    vector<bool> visited(N + 1, false);
    visited[1] = true;
    q.push(1);
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        for (int i = head[tp]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (visited[to]) continue;
            q.push(to);
            visited[to] = true;
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
