#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int A, B;
    cin >> A >> B;
    int res = 0, ten = 1;
    while (A > 0) {
        res = res + ten * abs(A % 10 - B % 10);
        ten *= 10;
        A /= 10; B /= 10;
    }
    cout << res << endl;
    return 0;
}
