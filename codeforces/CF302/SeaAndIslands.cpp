#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n, k;
    cin >> n >> k;
    int mx = (n * n + 1) / 2;
    if (k > mx) {
        cout << "NO" << endl;
        return 0;
    }
    int cnt = 0;
    cout << "YES" << endl;
    FOR(i, n) {
        FOR(j, n) {
            if (cnt < k && (i + j) % 2 == 0) {
                cout << 'L';
                ++cnt;
            }
            else cout << 'S';
        }
        cout << endl;
    }
    return 0;
}
