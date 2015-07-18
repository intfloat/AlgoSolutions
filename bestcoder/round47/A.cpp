#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
using namespace std;
inline void solve() {
    int n, P;
    scanf("%d %d", &n, &P);
    vector<ll> arr(n);
    FOR(i, n) scanf("%lld", &arr[i]);
    vector<ll> tmp;
    vector<ll> res;
    FOR(i, n) {
        tmp = arr;
        tmp[i] = P;
        for (int j = 1; j < n; ++j) {
            tmp[j] = max(0ll, tmp[j - 1]) + tmp[j];
        }
        res.push_back(*max_element(tmp.begin(), tmp.end()));
    }
    cout << *max_element(res.begin(), res.end()) << endl;
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        solve();
    }
    return 0;
}
