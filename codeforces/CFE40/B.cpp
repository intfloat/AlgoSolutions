#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool check(const string& s, int start, int mid, int end) {
    for (int i = start; i <= mid; ++i) {
        if (s[i] != s[mid + 1 + i - start]) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    string s;
    cin >> n >> s;
    int res = n;
    for (int i = 0; 2 * i + 1 < n; ++i) {
        if (check(s, 0, i, 2 * i + 1)) {
            res = min(res, n - i);
        }
    }
    cout << res << endl;
    return 0;
}
