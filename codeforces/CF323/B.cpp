#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 350;
int main() {
    int n, T;
    scanf("%d %d", &n, &T);
    vector<int> arr(n);
    vector<int> cnt(305, 0);
    FOR(i, n) {
        scanf("%d", &arr[i]);
        ++cnt[arr[i]];
    }
    vector<int> lis;
    FOR(i, min(T - 1, MAX_N)) FOR(j, n) arr.push_back(arr[j]);
    FOR(i, arr.size()) {
        int pos = upper_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        if (pos == lis.size()) lis.push_back(arr[i]);
        else lis[pos] = arr[i];
    }
    if (arr.size() == n * T) {
        cout << lis.size() << endl;
        return 0;
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    ll res = (ll)lis.size() + (ll)(T - MAX_N - 1) * mx;
    cout << res << endl;
    return 0;
}
