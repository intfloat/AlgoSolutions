#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int MAX_N = 200010;
int fa[MAX_N], nt[MAX_N];
int _find(int pos) {
    if (fa[pos] != pos) {
        fa[pos] = _find(fa[pos]);
    }
    return fa[pos];
}
int get_nt(int pos) {
    if (nt[pos] != pos) {
        nt[pos] = get_nt(nt[pos]);
    }
    return nt[pos];
}
inline void merge(int rx, int ry) {
    if (rx != ry) {
        fa[rx] = ry;
        if (_find(rx) == _find(rx + 1)) {
            nt[rx] = get_nt(rx + 1);
        }
        if (_find(ry) == _find(ry + 1)) {
            nt[ry] = get_nt(ry + 1);
        }
    }
}
int main() {
    int n, q, rp, rn, type, x, y;
    scanf("%d %d", &n, &q);
    FOR(i, n + 5) {
        fa[i] = nt[i] = i;
    }
    FOR(i, q) {
        scanf("%d %d %d", &type, &x, &y);
        if (type == 1) {
            int nx = get_nt(x), ny = get_nt(y);
            int rx = _find(nx);
            int ry = _find(ny);
            merge(rx, ry);
        }
        else if (type == 2) {
            int ptr = x;
            while (true) {
                ptr = get_nt(ptr);
                if (ptr >= y) break;
                rp = _find(ptr);
                rn = _find(get_nt(ptr + 1));
                merge(rp, rn);
                nt[ptr] = get_nt(ptr + 1);
                ++ptr;
            }
        }
        else {
            int nx = get_nt(x), ny = get_nt(y);
            int rx = _find(nx);
            int ry = _find(ny);
            if (rx == ry) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
