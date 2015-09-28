#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> h(n), mx(n);
    FOR(i, n) scanf("%d", &h[i]);
    mx[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        mx[i] = max(mx[i + 1], h[i + 1]);
    }
    FOR(i, n) {
        int res = max(0, mx[i] + 1 - h[i]);
        printf("%d ", res);
    }
    printf("\n");
    return 0;
}
