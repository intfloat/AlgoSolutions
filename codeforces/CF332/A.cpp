#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    int d12 = min(d1, d2 + d3), d13 = min(d2, d1 + d3), d23 = min(d3, d1 + d2);
    int res = d12 + d23 + d13;
    cout << res << endl;
    return 0;
}
