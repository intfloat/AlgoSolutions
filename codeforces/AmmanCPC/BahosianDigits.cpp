#include <bits/stdc++.h>
using namespace std;
int arr[255], sz;
string s;
void add(int idx, int d) {
    while (idx <= sz) {
        arr[idx] += d;
        idx += (idx & (-idx));
    }
}
int query(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += arr[pos];
        pos -= (pos & (-pos));
    }
    return ret;
}
inline void solve() {
    cin >> s;
    sz = s.size();
    for (int len = sz; len > 1; --len) {
        for (int i = 0; i < 10; ++i) {
            memset(arr, 0, sizeof arr);
            for (int j = 0; j < sz; ++j) {
                add(j + 1, s[j] - '0');
                add(j + 2, -(s[j] - '0'));
            }
            for (int j = 0; j <= sz - len; ++j) {
                int val = query(j + 1);
                val = (val % 10 + 10) % 10;
                if (val == i) {
                    continue;
                }
                int d = ((i - val) % 10 + 10) % 10;
                add(j + 1, d);
                add(j + 1 + len, -d);
            }
            bool ok = true;
            for (int j = sz - len + 1; j < sz; ++j) {
                int val = query(j + 1);
                val = (val % 10 + 10) % 10;
                if (val != i) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << len << endl;
                return;
            }
        }
    }
    cout << 1 << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
