#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, f;
    scanf("%d", &n);
    vector<int> pos(n + 1);
    FOR(i, n) {
        scanf("%d", &f);
        pos[f] = i + 1;
    }
    ll res = 0;
    for (int i = 1; i <= n - 1; ++i) {
        res += abs(pos[i + 1] - pos[i]);
    }
    cout << res << endl;
    return 0;
}
