#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    ll n, p;
    cin >> n >> p;
    vector<string> op(n);
    FOR(i, n) cin >> op[i];
    reverse(op.begin(), op.end());
    ll cur = 0, res = 0;
    FOR(i, n) {
        if (op[i] == "half") {
            res += cur * p;
            cur *= 2;
        }
        else {
            res += p * cur + p / 2;
            cur = (cur * 2 + 1);
        }
    }
    cout << res << endl;
    return 0;
}
