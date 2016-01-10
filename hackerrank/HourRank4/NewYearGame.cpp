#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline void solve() {
    int n, a, one = 0, two = 0;
    scanf("%d", &n);
    FOR(i, n) {
        scanf("%d", &a);
        if (a % 3 == 1) ++one;
        else if (a % 3 == 2) ++two;
    }
    if (one % 2 == 0 && two % 2 == 0) {
        printf("Koca\n");
    }
    else {
        printf("Balsa\n");
    }
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
