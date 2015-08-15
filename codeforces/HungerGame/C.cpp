#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int n;
inline int left(int pos) {
    return (pos + 1) % n;
}
inline int right(int pos) {
    return (pos - 1 + n) % n;
}
inline int next(int pos) {
    return (pos + 3) % n;
}
int main() {
    int x1, x2;
    scanf("%d", &n);
    vector<ll> b(n);
    FOR(i, n) scanf("%I64d", &b[i]);
    ll sm = accumulate(b.begin(), b.end(), 0ll);
    if (sm % 3 != 0) {
        printf("-1\n");
        return 0;
    }
    sm = sm / 3ll;
    vector<ll> res(n);
    if (n % 3) {
        vector<ll> val;
        vector<int> idx;
        int cur = 0;
        while (true) {
            int x1 = left(cur);
            int x2 = right(next(cur));
            val.push_back(b[x2] - b[x1]);
            cur = next(cur);
            if (cur == 0) break;
            idx.push_back(cur);
        }
        for (int i = 1; i < val.size(); ++i) {
            val[i] += val[i - 1];
        }
        if (val.back() != 0) {
            printf("-1\n");
            return 0;
        }
        // n * res[0] + sum(val) = sm
        ll t = sm - accumulate(val.begin(), val.end(), 0ll);
        if (t % n) {
            printf("-1\n");
            return 0;
        }
        res[0] = t / n;
        FOR(i, idx.size()) {
            res[idx[i]] = res[0] + val[i];
        }
    }
    else {
        vector<ll> val[3];
        for (int i = 0; i < n; ++i) {
            int x1 = left(i);
            int x2 = right(i + 3);
            if (val[i % 3].size() < n / 3)
                val[i % 3].push_back(b[x2] - b[x1]);
        }
        FOR(i, 3) for (int j = 1; j < n / 3; ++j) {
            val[i][j] += val[i][j - 1];
        }
        if (val[0].back() || val[1].back() || val[2].back()) {
            printf("-1\n");
            return 0;
        }
        // n / 3 * (res[0] + res[1] + res[2]) + sum(val) = sm
        ll t = sm;
        FOR(i, 3) t -= accumulate(val[i].begin(), val[i].end(), 0ll);
        t *= 3ll;
        if (t % n) { printf("-1\n"); return 0; }
        res[0] = t / n; res[1] = res[2] = 0;
        FOR(i, 3) for (int j = 1; j < n / 3; ++j) {
            if (i + j * 3 < n) {
                res[i + j * 3] = val[i][j - 1] + res[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%I64d ", res[i]);
    }
    printf("\n");
    return 0;
}
