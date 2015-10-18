#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int MAX_N = 200005;
ll cnt[MAX_N], rem[MAX_N];
inline void update(ll* f, int pos, int val) {
    if (pos == 0) return;
    while (pos < MAX_N) {
        f[pos] += val;
        pos += pos & (-pos);
    }
}
inline ll query(ll* f, int pos) {
    ll ret = 0;
    while (pos > 0) {
        ret += f[pos];
        pos -= pos & (-pos);
    }
    return ret;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pii> t(m + 1);
    memset(cnt, 0, sizeof cnt);
    memset(rem, 0, sizeof rem);
    FOR(i, m) {
        scanf("%d", &t[i + 1].first);
        t[i + 1].second = i + 1;
        update(rem, i + 1, t[i + 1].first);
    }
    sort(t.begin() + 1, t.end());
    vector<piii> arr(n);
    FOR(i, n) {
        scanf("%d %d", &arr[i].first.first, &arr[i].first.second);
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    int ptr = 1;
    vector<int> res(n + 1);
    FOR(i, n) {
        int pre = arr[i].first.first;
        int need = arr[i].first.second;
        int index = arr[i].second;
        while (ptr <= m && t[ptr].first <= pre) {
            update(cnt, t[ptr].second, 1);
            update(rem, t[ptr].second, -t[ptr].first);
            ++ptr;
        }
        ll mx = query(rem, m) - pre * (m - query(cnt, m));
        if (mx < need) {
            res[index] = 0;
            continue;
        }
        int l = 1, r = m;
        while (l < r) {
            int mid = (l + r) / 2;
            ll tot = query(rem, mid) - pre * (mid - query(cnt, mid));
            if (tot >= need) r = mid;
            else l = mid + 1;
        }
        res[index] = l;
    }
    FOR(i, n) printf("%d ", res[i + 1]);
    printf("\n");
    return 0;
}
