#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 24 * 60 * 60;
ll get() {
    ll ret = 0, val;
    char cc;
    cin >> val >> cc;
    ret += val * 60 * 60;
    cin >> val >> cc;
    ret += val * 60;
    cin >> val;
    ret += val;
    return ret;
}
void solve() {
    ll G = get(), W = get(), H = get(), B = get(), X = get();
    --W; --B;
    ll D, cur = 0;
    cin >> D;
    D = D * MOD;
    map<ll, ll> mp;
    ll step = 1, res = 0;
    bool first = true;
    vector<ll> arr(MOD), pos(MOD, -1), ss(MOD);
    FOR(i, MOD) {
        if (i >= G && i <= W) arr[i] = i;
        else if (i >= H && i <= B) arr[i] = i;
        else if (i > W && i < H) arr[i] = W;
        else if (i < G) arr[i] = B;
        else if (i > B) arr[i] = B;
    }
    while (true) {
        if (cur + X >= D) {
            break;
        }
        ll up = cur + X;
        ll feed = arr[up % MOD] + up / MOD * MOD;
        if (feed > up) {
            feed -= MOD;
            assert(feed <= up);
        }
        if (feed < 0 || feed <= cur) {
            cout << -1 << endl;
            return;
        }
        ll rem = feed % MOD;
        if (first && pos[rem] != -1) {
            first = false;
            ll len = feed - pos[rem], diff = step - mp[rem];
            ll num = (D - feed) / len;
            if (num == 0) {
                cur = feed;
                ++res;
                continue;
            }
            --num;
            res += num * diff;
            cur = feed + num * len;
            ++res;
        }
        else {
            pos[rem] = feed;
            ss[step] = feed;
            mp[rem] = step++;
            cur = feed;
            ++res;
        }
    }
    printf("%lld\n", res);
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
