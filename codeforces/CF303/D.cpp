#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    FOR(i, n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll cur = 0, res = 0;
    FOR(i, arr.size()) {
        if (cur <= arr[i]) {
            ++res;
            cur += arr[i];
        }        
    }
    cout << res << endl;
    return 0;
}
