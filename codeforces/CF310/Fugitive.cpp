#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n, m;
    ll len;
    vector<pair<ll, ll> > land;
    multiset<pair<ll, int> > st;
    multiset<pair<ll, int> >::iterator it;
    cin >> n >> m;
    land.resize(n);
    FOR(i, n) {
        cin >> land[i].first >> land[i].second;
    }
    FOR(i, m) {
        cin >> len;
        st.insert(make_pair(len, i));
    }
    vector<int> res(n - 1);
    vector<pair<pair<ll, ll>, int> > arr;
    for (int i = 1; i < n; ++i) {
        arr.push_back(make_pair(make_pair(land[i].second - land[i - 1].first, land[i].first - land[i - 1].second), i - 1));
    }
    sort(arr.begin(), arr.end());
    bool ok = true;
    FOR(i, arr.size()) {
        ll mn = arr[i].first.second, mx = arr[i].first.first;
        int idx = arr[i].second;
        it = st.lower_bound(make_pair(mn, -1));
        if (it == st.end() || (*it).first > mx) {
            ok = false;
            break;
        }
        else {
            res[idx] = ((*it).second + 1);
            st.erase(it);
        }
    }
    if (ok) {
        cout << "Yes" << endl;
        FOR(i, res.size()) cout << res[i] << " ";
        cout << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
