#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> arr(n);
    FOR(i, n) {
        scanf("%d", &arr[i]);
    }
    vector<pii> slope;
    for (int i = 1; i < n; ++i) {
        slope.push_back({abs(arr[i] - arr[i - 1]), i});
    }
    sort(slope.begin(), slope.end(), greater<pii>());
    vector<int> low(n), up(n);
    set<pii> st;
    st.insert({n - 1, 0});
    FOR(i, slope.size()) {
        int pos = slope[i].second;
        pii cur = make_pair(pos, -1);
        pii val = *st.lower_bound(cur);
        low[pos] = val.second;
        up[pos] = val.first;
        st.erase(val);
        if (val.first > pos) st.insert({val.first, pos});
        if (pos - 1 > val.second) st.insert({pos - 1, val.second});
    }
    FOR(i, q) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l; --r;
        ll res = 0;
        for (int j = l + 1; j <= r; ++j) {
            int rr = min(up[j], r);
            int lt = max(low[j], l);
            res += (ll)abs(arr[j] - arr[j - 1]) * (ll)(rr - j + 1) * (ll)(j - lt);
        }
        cout << res << endl;
    }
    return 0;
}
