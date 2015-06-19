#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int N, res = 0, x1, x2, y1, y2;
    cin >> N;
    FOR(i, N) {
        cin >> x1 >> y1 >> x2 >> y2;
        res += (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    cout << res << endl;
    return 0;
}
