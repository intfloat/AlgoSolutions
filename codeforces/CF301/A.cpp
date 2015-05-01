#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int res = 0;
    FOR(i, a.size()) {
        int t1 = a[i] - '0';
        int t2 = b[i] - '0';        
        if (t1 > t2) swap(t1, t2);
        res += min(t2 - t1, t1 - t2 + 10);
    }
    cout << res << endl;
    return 0;
}
