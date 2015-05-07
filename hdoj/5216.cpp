#include <stdio.h>
#include <algorithm>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(m), b(m);
    FOR(i, m) scanf("%d", &a[i]);
    FOR(i, m) scanf("%d", &b[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    FOR(i, m) {
        if (a[i] > b[i]) {
            printf("Stupid BrotherK!\n");
            return;
        }        
    }
    int res = a[0] - 1;
    FOR(i, m - 1) {
        if (a[i + 1] > b[i])
            res = max(res, a[i + 1] - b[i] - 1);
    }
    res = max(res, n - b[m - 1]);
    printf("%.6f\n", (double)res);
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) solve();
    return 0;
}
