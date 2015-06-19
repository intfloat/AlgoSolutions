#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    ll w, m;
    cin >> w >> m;
    while (m != 0) {
        while (m % w == 0) m /= w;
        if (m % w == 1) m = (m - 1) / w;
        else if (m % w == w - 1) m = (m + 1) / w;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
