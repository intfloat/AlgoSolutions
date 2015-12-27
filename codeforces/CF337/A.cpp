#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    cin >> n;
    if (n % 2) {
        cout << 0 << endl;
    }
    else {
        n /= 2;
        if (n % 2) {
            cout << n / 2 << endl;
        }
        else {
            cout << (n / 2) - 1 << endl;
        }
    }
    return 0;
}
