#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int t;
    cin >> t;
    ll res = 0;
    FOR(i, t) {
        if (i % 2 == 0) res += (i + 2) / 2;
        else res += (i + 2 + 1) / 2;
    }
    printf("%d\n", res);
    return 0;
}
