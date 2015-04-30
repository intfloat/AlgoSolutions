#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cassert>
#include <string.h>
#include <limits.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;
const int MAX_N = 1105;
const int MAX_M = 110005;
const int INF = INT_MAX / 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], w[MAX_M], ptr, acc[MAX_N];
int rhead[MAX_N], rpnt[MAX_M], rnt[MAX_M], rw[MAX_M], rptr, rdis[MAX_N];
bool inq[MAX_N];
int N, M, S, T, K;
void addedge(int from, int to, int cost) {
    nt[ptr] = head[from]; head[from] = ptr; w[ptr] = cost; pnt[ptr++] = to;
    rnt[rptr] = rhead[to]; rhead[to] = rptr; rw[rptr] = cost; rpnt[rptr++] = from;
}

void spfa() {
    memset(inq, false, sizeof inq);
    queue<int> q; q.push(T);
    rdis[T] = 0; inq[T] = true;
    while (!q.empty()) {
        int tp = q.front(); q.pop(); inq[tp] = false;
        for (int i = rhead[tp]; i != -1; i = rnt[i]) {
            int to = rpnt[i];
            if (rdis[tp] + rw[i] < rdis[to]) {
                rdis[to] = rdis[tp] + rw[i];
                if (!inq[to]) {
                    q.push(to);
                    inq[to] = true;
                }
            }
        }
    }
    return;
}

struct Node {
    int v, total, forward;
    Node(int _v, int _t, int _f): v(_v), total(_t), forward(_f) {}
    bool operator<(const Node& that) const {
        if (total != that.total) return total > that.total;
        else return forward > that.forward;
    }
};
int astar() {
    if (S == T) ++K;
    priority_queue<Node> q;
    int cnt = 0;
    memset(acc, 0, sizeof acc);    
    q.push(Node(S, 0 + rdis[S], 0));
    while (!q.empty()) {        
        Node tp = q.top(); q.pop();
        ++acc[tp.v];
        if (tp.v == T) {
            ++cnt;
            if (cnt == K) return tp.forward;
        }
        for (int i = head[tp.v]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (acc[to] <= K && rdis[to] < INF) {                
                q.push(Node(to, tp.forward + w[i] + rdis[to], tp.forward + w[i]));
            }
        }
    }
    return -1;
}

int main() {
    int from, to, cost;
    scanf("%d %d", &N, &M);
    memset(head, -1, sizeof head);
    memset(rhead, -1, sizeof rhead);
    ptr = rptr = 0;
    FOR(i, M) {
        scanf("%d %d %d", &from, &to, &cost);
        addedge(from, to, cost);
    }
    scanf("%d %d %d", &S, &T, &K);
    FOR(i, MAX_N) rdis[i] = INF;
    spfa();
    if (rdis[S] == INF) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", astar());
    return 0;
}
