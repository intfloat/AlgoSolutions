#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int h, q, hei, ans;
    ll left, right;
    cin >> h >> q;
    ll mn = (1ll << (h - 1));
    ll mx = (1ll << h) - 1ll;
    vector<pair<ll, ll> > arr;
    FOR(i, q) {
        cin >> hei >> left >> right >> ans;
        FOR(j, h - hei) {
            left = left * 2ll;
            right = right * 2ll + 1ll;
        }
        if (ans == 0) {
            arr.push_back(make_pair(left, right));
        }
        else {
            if (mn <= left - 1) arr.push_back(make_pair(mn, left - 1));
            if (right + 1 <= mx) arr.push_back(make_pair(right + 1, mx));
        }
    }
    arr.push_back(make_pair(mx + 1, mx + 1));
    sort(arr.begin(), arr.end());
    vector<ll> res;
    ll cur = mn - 1;
    FOR(i, arr.size()) {
        if (arr[i].first > cur + 1 && res.size() < 5) {
            for (ll j = cur + 1; j < arr[i].first && res.size() < 5; ++j) {
                res.push_back(j);
            }
            cur = arr[i].second;
        }
        else {
            cur = max(cur, arr[i].second);
        }
    }
    if (res.empty()) {
        cout << "Game cheated!" << endl;
    }
    else if (res.size() > 1) {
        cout << "Data not sufficient!" << endl;
    }
    else {
        cout << res[0] << endl;
    }
    return 0;
}
