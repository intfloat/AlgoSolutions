#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, m, c, t;
    cin >> n >> m;
    vector<int> on(m + 1, 0);
    FOR(i, n) {
        cin >> c;
        FOR(j, c) {
            cin >> t;
            on[t] = 1;
        }
    }
    bool ok = (accumulate(on.begin(), on.end(), 0) == m);
    if (ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}
