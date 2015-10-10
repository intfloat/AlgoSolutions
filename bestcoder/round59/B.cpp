#include <stdio.h>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
struct Node {
    ll A, B, C;
    Node(ll a, ll b, ll c): A(a), B(b), C(c) {}
    bool operator<(const Node& that) const {
        ll t = B * that.C - that.B * C;
        return t > 0;
    }
};
inline void solve() {
    int n, t, A, B, C;
    scanf("%d %d", &n, &t);
    vector<Node> arr;
    vector<ll> dp(t + 1, 0);
    FOR(i, n) {
        scanf("%d %d %d", &A, &B, &C);
        arr.push_back(Node(A, B, C));
    }
    sort(arr.begin(), arr.end());
    FOR(i, n) {
        for (int j = t; j >= arr[i].C; --j) {
            dp[j] = max(dp[j], dp[j - arr[i].C] + arr[i].A - arr[i].B * j);
        }
    }
    ll res = *max_element(dp.begin(), dp.end());
    printf("%lld\n", res);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
