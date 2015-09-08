#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
int parent[MAX_N], sz[MAX_N];
int N, numberOfSet;

inline void init() {
    numberOfSet = N;
    for (int i = 0; i < N; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int _find(int p) {
    if (p == parent[p]) return p;
    parent[p] = _find(parent[p]);
    return parent[p];
}
inline void merge(int p, int q) {
    int rootP = _find(p);
    int rootQ = _find(q);
    if (rootP == rootQ) return;
    if (sz[rootP] < sz[rootQ]) {
        parent[rootP] = rootQ;
        sz[rootQ] += sz[rootP];
    }
    else {
        parent[rootQ] = rootP;
        sz[rootP] += sz[rootQ];
    }
    --numberOfSet;
}

int main() {
    return 0;
}
