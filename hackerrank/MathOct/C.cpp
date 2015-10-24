#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline void solve() {
    ll N, K;
    cin >> N >> K;
    ll mx = N * (N + 1) / 2ll;
    ll mn = -mx + 2ll;
    ll odd = (N + 1) / 2;
    ll tmp = (K % 2 + 2) % 2;
    if (K < mn || K > mx) printf("NO\n");
    else if (odd % 2 != tmp) printf("NO\n");
    else printf("YES\n");
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
