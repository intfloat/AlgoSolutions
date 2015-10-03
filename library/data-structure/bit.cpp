#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
typedef int E;
E f[MAX_N];
int n;
inline void init() {
    memset(f, 0, sizeof f);
}
inline void update(int pos, E val) {
    if (pos == 0) return;
    while (pos <= n) {
        f[pos] += val;
        pos += pos & (-pos);
    }
}
inline E query(int pos) {
    E ret = 0;
    while (pos > 0) {
        ret += f[pos];
        pos -= pos & (-pos);
    }
    return ret;
}
int main() {
    return 0;
}
