#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    vector<int> pos(m + 1, 0);
    vector<int> res(m + 1, 0);
    FOR(i, n) {
        scanf("%d", &a[i]);
        if (a[i] <= m) {
            ++pos[a[i]];
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (pos[i]) {
            int sz = pos[i];
            for (int j = i; j <= m; j += i) {
                res[j] += sz;
            }
        }
    }
    auto it = max_element(res.begin(), res.end());
    if (*it == 0) {
        printf("1 0\n");
    }
    else {
        int lcm = it - res.begin();
        printf("%d %d\n", lcm, *it);
        FOR(i, n) {
            if (lcm % a[i] == 0) {
                printf("%d ", i + 1);
            }
        }
    }
    printf("\n");
    return 0;
}
