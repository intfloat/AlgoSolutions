#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int a, b;
    cin >> a >> b;
    int r1 = min(a, b);
    int r2 = ((a + b) - 2 * r1) / 2;
    cout << r1 << " " << r2 << endl;
    return 0;
}
