#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    char a[20], b[20];
    scanf("%s %s", a, b);
    int len = strlen(a);
    FOR(i, len) {
        if (a[i] == '?' || b[i] == '?') {
            continue;
        }
        if (a[i] != b[i]) {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
