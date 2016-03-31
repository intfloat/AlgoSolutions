#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    --a;
    a = (a + b) % n;
    if (a < 0) a = (a + n) % n;
    cout << a + 1 << endl;
    return 0;
}
