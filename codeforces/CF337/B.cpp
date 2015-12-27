#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) {
        scanf("%d", &arr[i]);
    }
    int mn = *min_element(arr.begin(), arr.end());
    vector<int> pos;
    FOR(i, n) {
        if (arr[i] == mn) {
            pos.push_back(i);
        }
    }
    pos.push_back(pos[0] + n);
    ll res = (ll)mn * (ll)n;
    int mx = 0;
    FOR(i, pos.size() - 1) {
        mx = max(pos[i + 1] - pos[i] - 1, mx);
    }
    res += mx;
    cout << res << endl;
    return 0;
}
