#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 40005;
int head[MAX_N], nt[MAX_N * 2], pnt[MAX_N * 2], wei[MAX_N * 2], ptr1;
int head2[MAX_N], next2[505], pnt2[505], ptr2;
int dis[MAX_N], p[MAX_N];
bool visited[MAX_N];

vector<pair<pair<int, int>, int> > res;

void addedge(int u, int v, int w) {
    nt[ptr1] = head[u]; head[u] = ptr1; pnt[ptr1] = v; wei[ptr1++] = w;
    nt[ptr1] = head[v]; head[v] = ptr1; pnt[ptr1] = u; wei[ptr1++] = w;
}

void addquery(int u, int v) {
    next2[ptr2] = head2[u]; head2[u] = ptr2; pnt2[ptr2++] = v;
    next2[ptr2] = head2[v]; head2[v] = ptr2; pnt2[ptr2++] = u;
}

int _find(int idx) {
    if (p[idx] == idx) return idx;
    p[idx] = _find(p[idx]);
    return p[idx];
}

void tarjan_lca(int pos) {
    // implement it in a non-recursive way to avoid stack overflow...
    stack<pair<int, int> > s;
    s.push(make_pair(1, -2));
    while (!s.empty()) {
        pair<int, int> tp = s.top(); s.pop(); 
        int idx = tp.first;
        int ps = tp.second;
        // cout << idx << " " << ps << endl;
        visited[idx] = true;
        if (ps == -2) {
            for (int i = head2[idx]; i != -1; i = next2[i]) {        
                if (visited[pnt2[i]]) {
                    // cout << idx << " " << pnt2[i] << endl;
                    pair<int, int> cur = make_pair(min(idx, pnt2[i]), max(idx, pnt2[i]));
                    res.push_back(make_pair(cur, _find(pnt2[i])));
                }
            }            
            if (head[idx] == -1) continue;
            int nch = head[idx];
            while (nch != -1 && visited[pnt[nch]]) nch = nt[nch];
            if (nch == -1) continue;
            dis[pnt[nch]] = dis[idx] + wei[nch];
            s.push(make_pair(idx, nch));
            s.push(make_pair(pnt[nch], -2));
        }
        else if (ps != -1) {            
            p[pnt[ps]] = idx;
            int nch = nt[ps];
            while (nch != -1 && visited[pnt[nch]]) nch = nt[nch];
            if (nch == -1) continue;
            if (!visited[pnt[nch]]) {
                dis[pnt[nch]] = dis[idx] + wei[nch];
                s.push(make_pair(idx, nch));
                s.push(make_pair(pnt[nch], -2));
            }
        }        
    }
    return;
}

int main() {
    int T, n, m, x, y, w;
    scanf("%d", &T);
    FOR(tt, T) {
        ptr1 = ptr2 = 0;
        res.clear();
        scanf("%d %d", &n, &m);
        FOR(i, MAX_N) {
            visited[i] = false;
            p[i] = i;
            head[i] = head2[i] = -1;
            dis[i] = 0;
        }
        // dis[1] = 0;
        FOR(i, n - 1) {
            scanf("%d %d %d", &x, &y, &w);
            addedge(x, y, w);
        }
        int A[205], B[205];
        FOR(i, m) {
            scanf("%d %d", A + i, B + i);
            if (A[i] > B[i]) swap(A[i], B[i]);
            addquery(A[i], B[i]);
        }
        tarjan_lca(1);
        FOR(i, m) {
            FOR(j, res.size()) {
                if (res[j].first == make_pair(A[i], B[i])) {
                    printf("%d\n", dis[A[i]] + dis[B[i]] - 2 * dis[res[j].second]);
                    break;
                }
            }
        }
    }
    return 0;
}
