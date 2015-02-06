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
    Node* ch[2];
    Node() { ch[0] = ch[1] = NULL; }
};
Node* root;

void insert_trie(int number) {
    Node* cur = root;
    for (int i = 30; i >= 0; --i) {
        int dir = 0;
        if (number & (1 << i)) dir = 1;
        if (cur->ch[dir] == NULL) cur->ch[dir] = new Node();
        cur = cur->ch[dir];
    }
    return;
}

int solve(int number) {
    Node* cur = root;
    int ret = 0;
    for (int i = 30; i >= 0; --i) {
        int dir = 1;
        if (number & (1 << i)) dir = 0;
        if (cur->ch[dir] == NULL) {
            cur = cur->ch[1 - dir];           
        }
        else {
            cur = cur->ch[dir];
            ret = ret | (1 << i);
        }
    }    
    return ret;
}

int main() {
    int x, y, w;
    while (scanf("%d", &N) != EOF) {
        memset(head, -1, sizeof(head));
        ptr = 0;
        FOR(i, N - 1) {
            scanf("%d %d %d", &x, &y, &w);
            // ++x; ++y; // comment this line for bzoj
            addedge(x, y, w);
        }
        int res = 0;
        bfs();
        root = new Node();
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
