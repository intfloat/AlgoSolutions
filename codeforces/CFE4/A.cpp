#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, p, q;
    string s;
    cin >> n >> p >> q;
    cin >> s;
    FOR(i, 200) {
        if (p * i > n) break;
        if ((n - i * p) % q == 0) {
            int nq = (n - i * p) / q;
            cout << i + nq << endl;
            FOR(j, i) cout << s.substr(j * p, p) << endl;
            FOR(j, nq) cout << s.substr(i * p + j * q, q) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
