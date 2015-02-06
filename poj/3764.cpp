#include <queue>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 100005;
int head[MAX_N], pnt[MAX_N * 2], nt[MAX_N * 2], wei[MAX_N * 2];
int ptr, N, val[MAX_N];

void addedge(int from, int to, int w) {
    nt[ptr] = head[from]; head[from] = ptr; pnt[ptr] = to; wei[ptr++] = w;
    nt[ptr] = head[to]; head[to] = ptr; pnt[ptr] = from; wei[ptr++] = w;
}

void bfs() {
    bool visited[MAX_N];
    memset(visited, false, sizeof(visited));
    visited[1] = true; val[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        for (int i = head[tp]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (visited[to]) continue;
            val[to] = val[tp] ^ wei[i];
            visited[to] = true;
            q.push(to);
        }
    }
    // for (int i = 1; i <= N; ++i) assert(visited[i]);    
    return;
}

struct Node {
    int ch[2];
    Node() { ch[0] = ch[1] = -1; }
};
Node arr[MAX_N * 32];
int tptr;

void insert_trie(int number) {
    int cur = 0;
    for (int i = 30; i >= 0; --i) {
        int dir = 0;
        if (number & (1 << i)) dir = 1;
        if (arr[cur].ch[dir] == -1) arr[cur].ch[dir] = tptr++;
        cur = arr[cur].ch[dir];
    }
    return;
}

int solve(int number) {
    int cur = 0;
    int ret = 0;
    for (int i = 30; i >= 0; --i) {
        int dir = 1;
        if (number & (1 << i)) dir = 0;
        if (arr[cur].ch[dir] == -1) {
            cur = arr[cur].ch[1 - dir];           
        }
        else {
            cur = arr[cur].ch[dir];
            ret = ret | (1 << i);
        }
    }    
    return ret;
}

int main() {
    int x, y, w;
    while (scanf("%d", &N) != EOF) {
        FOR(i, N + 1) head[i] = -1;
        FOR(i, N * 32 + 1) arr[i].ch[0] = arr[i].ch[1] = -1;
        ptr = 0; tptr = 1;
        FOR(i, N - 1) {
            scanf("%d %d %d", &x, &y, &w);
            ++x; ++y;
            addedge(x, y, w);
        }
        int res = 0;
        bfs();
        // FOR(i, N) cout << "val: " << val[i + 1] << endl;
        insert_trie(val[1]);
        for (int i = 2; i <= N; ++i) {
            int cur = solve(val[i]);
            insert_trie(val[i]);
            res = max(res, cur);
        }        
        printf("%d\n", res);
    }
    return 0;
}
