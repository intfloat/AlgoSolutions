#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int solve(int num) {
    int ret = 0;
    while (num > 0) {
        ret += num % 10;
        num /= 10;
    }
    return ret;
}
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int cc = solve(C);
    int res = -1, mn = 12345;
    for (int i = A; i <= B; ++i) {
        int cur = abs(cc - solve(i));
        if (cur < mn) {
            mn = cur;
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}
