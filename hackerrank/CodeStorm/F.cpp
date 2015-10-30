#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
vector<int> arr;
inline bool ok(vector<int>& seq) {
    for (int i = 1; i < (int)seq.size(); ++i) {
        if (arr[seq[i]] <= arr[seq[i - 1]]) return false;
    }
    return true;
}
int main() {
    int n;
    scanf("%d", &n);
    arr.resize(n);
    vector<int> pv(n, -1);
    FOR(i, n) scanf("%d", &arr[i]);
    vector<pii> tt;
    FOR(i, n) tt.push_back(make_pair(-arr[i], i));
    sort(tt.begin(), tt.end());
    int mn = -1;
    FOR(i, n) {
        int pos = tt[i].second;
        if (mn < 0) {
            pv[pos] = -1;
            mn = pos;
        }
        else {
            if (mn < pos) {
                pv[pos] = mn;
            }
            else {
                pv[pos] = -1;
                mn = pos;
            }
        }
    }
    ll res = 1;
    int ptr = n - 1;
    while (ptr >= 0) {
        if (pv[ptr] < 0) {
            res = (res * 2ll) % MOD;
            --ptr;
            continue;
        }
        do {
            vector<int> low, up;
            for (int i = pv[ptr]; i < ptr; ++i) {
                if (arr[i] >= arr[ptr]) {
                    up.push_back(i);
                }
                else low.push_back(i);
            }
            if (!ok(low) || !ok(up)) {
                printf("0\n");
                return 0;
            }
            if (low.empty() || pv[low[0]] >= pv[ptr]) {
                ptr = pv[ptr] - 1;
                res = (res * 2ll) % MOD;
                break;
            }
            else {
                ptr = pv[ptr];
                pv[ptr] = pv[low[0]];
                arr[ptr] = arr[low[0]];
            }
        } while (true);
    }
    printf("%lld\n", res);
    return 0;
}
