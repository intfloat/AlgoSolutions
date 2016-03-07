#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
map<pii, int> cnt;
int main() {
    int n, x, y;
    scanf("%d", &n);
    vector<pii> arr;
    FOR(i, n) {
        scanf("%d %d", &x, &y);
        arr.push_back({x, y});
        ++cnt[{x, y}];
    }
    ll res = 0;
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    int ptr = 0;
    while (ptr < arr.size()) {
        int j = ptr;
        ll tot = 0;
        while (j < arr.size() && arr[j].first == arr[ptr].first) {
            ll tmp = cnt[arr[j]];
            tot += tmp;
            // res -= tmp * (tmp - 1) / 2;
            ++j;
        }
        res += tot * (tot - 1) / 2;
        ptr = j;
    }
    FOR(i, arr.size()) {
        swap(arr[i].first, arr[i].second);
    }
    sort(arr.begin(), arr.end());
    ptr = 0;
    while (ptr < arr.size()) {
        int j = ptr;
        ll tot = 0;
        while (j < arr.size() && arr[j].first == arr[ptr].first) {
            pii val = make_pair(arr[j].second, arr[j].first);
            ll tmp = cnt[val];
            tot += tmp;
            res -= tmp * (tmp - 1) / 2;
            ++j;
        }
        res += tot * (tot - 1) / 2;
        ptr = j;
    }
    cout << res << endl;
    return 0;
}
