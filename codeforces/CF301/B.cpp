#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    vector<int> arr(k);
    FOR(i, k) cin >> arr[i];
    int cnt = (n + 1) / 2;
    if (n % 2 == 0) cnt = n / 2 + 1;
    vector<int> res;
    FOR(i, k) {
        if (arr[i] >= y) res.push_back(arr[i]);
    }
    int ys = cnt - res.size();
    while (res.size() < cnt) res.push_back(y);
    FOR(i, k) {
        if (arr[i] < y) res.push_back(arr[i]);
    }
    if (res.size() > n) cout << -1 << endl;
    else {
        int os = n - res.size();
        while (res.size() < n) res.push_back(1);
        int acc = accumulate(res.begin(), res.end(), 0);
        if (acc > x) cout << -1 << endl;
        else {
            FOR(i, ys) cout << y << " ";
            FOR(i, os) cout << 1 << " ";
            cout << endl;
        }
    }
    return 0;
}
