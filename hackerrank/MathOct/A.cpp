#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == 0 || b == 0) printf("First\n");
    else if (a % 2 != b % 2) printf("First\n");
    else if (a % 2 == 0 && b % 2 == 0) printf("Second\n");
    else printf("Second\n");
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
