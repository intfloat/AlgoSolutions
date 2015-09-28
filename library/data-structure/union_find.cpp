#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
int N, fa[MAX_N];

inline void init() {
    for (int i = 0; i < N; ++i) {
        fa[i] = i;
    }
}
int _find(int x) {
    if (x == fa[x]) return x;
    fa[x] = _find(fa[x]);
    return fa[x];
}
inline void merge(int x, int y) {
    fa[x] = y;
}

int main() {
    return 0;
}
