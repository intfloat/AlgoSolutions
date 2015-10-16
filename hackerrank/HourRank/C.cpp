#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> arr, primes;
vector<vector<int> > factors;
const int MAX_N = 500005;
void preprocess() {
    vector<bool> ok(MAX_N, true);
    factors.resize(MAX_N);
    for (int i = 2; i < MAX_N; ++i) {
        if (ok[i]) {
            primes.push_back(i);
            for (int j = i; j < MAX_N; j += i) {
                ok[j] = false;
                factors[j].push_back(i);
            }
        }
    }
}
int cnt[MAX_N];
inline void solve() {
    int n;
    scanf("%d", &n);
    arr.resize(n);
    memset(cnt, 0, sizeof cnt);
    vector<int> cand;
    FOR(i, n) {
        scanf("%d", &arr[i]);
        FOR(j, factors[arr[i]].size()) {
            int p = factors[arr[i]][j];
            ++cnt[p];
            if (cnt[p] == n / 2) cand.push_back(p);
        }
    }
    if ((int)cand.size() == 1) {
        if (cnt[cand[0]] == n) printf("YES\n");
        else printf("NO\n");
        return;
    }
    FOR(i, cand.size()) for (int j = i + 1; j < (int)cand.size(); ++j) {
        int p1 = cand[i], p2 = cand[j];
        bool ok = true;
        FOR(k, n) {
            if (arr[k] % p1 && arr[k] % p2) {
                ok = false;
                break;
            }
        }
        if (ok) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}
int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
