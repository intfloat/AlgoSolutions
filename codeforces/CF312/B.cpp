#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    FOR(i, n) cin >> arr[i];
    map<int, int> cnt;
    map<int, int> left, right;
    int mx = 0;
    FOR(i, n) {
        ++cnt[arr[i]];
        mx = max(mx, cnt[arr[i]]);
        if (left.find(arr[i]) == left.end()) {
            left[arr[i]] = i;
        }
        right[arr[i]] = i;
    }
    int dis = (int)1e8;
    pair<int, int> res;
    FOR(i, n) {
        if (cnt[arr[i]] == mx && right[arr[i]] - left[arr[i]] < dis) {
            dis = right[arr[i]] - left[arr[i]];
            res = make_pair(left[arr[i]] + 1, right[arr[i]] + 1);
        }
    }
    cout << res.first << " " << res.second << endl;
    return 0;
}
