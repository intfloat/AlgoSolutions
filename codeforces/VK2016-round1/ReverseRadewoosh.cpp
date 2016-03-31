#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, c;
int solve(const vector<int>& p, const vector<int>& t) {
    vector<int> sm = t;
    for (int i = 1; i < n; ++i) {
        sm[i] += sm[i - 1];
    }
    int ret = 0;
    FOR(i, n) {
        ret += max(0, p[i] - c * sm[i]);
    }
    return ret;
}
int main() {
    cin >> n >> c;
    vector<int> p(n), t(n);
    FOR(i, n) cin >> p[i];
    FOR(i, n) cin >> t[i];
    int res1 = solve(p, t);
    reverse(p.begin(), p.end());
    reverse(t.begin(), t.end());
    int res2 = solve(p, t);
    if (res1 > res2) {
        printf("Limak\n");
    }
    else if (res1 < res2) {
        printf("Radewoosh\n");
    }
    else printf("Tie\n");
    return 0;
}
