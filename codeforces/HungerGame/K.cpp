// by adamant, don't want to write it again...
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int base = 37;
const int maxn = 3e5;
int arr[maxn][2];
void add(int x, int p, int y) {
    for(; x < maxn; x += x & -x)
        arr[x][y] += p;
}
int get(int x, int y) {
    int ret = 0;
    for(; x; x -= x & -x)
        ret += arr[x][y];
    return ret;
}
int get(int l, int r, int t) {
    return get(r, t) - get(l - 1, t);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string t;
    int q;
    cin >> t >> q;
    string s = "##";
    for(auto c: t)
        s += c + string("#");
    int n = s.size();
    int pw[n];
    pw[0] = 1;
    for(int i = 1; i < n; i++)
        pw[i] = pw[i - 1] * base;
    for(int i = 1; i < n; i++) {
        add(i, s[i] * pw[i], 0);
        add(i, s[i] * pw[n - i], 1);
    }
    while(q--) {
        int t, p;
        cin >> t >> p;
        if(t == 1) {
            p = 2 * p;
            char x;
            cin >> x;
            add(p, -s[p] * pw[p], 0);
            add(p, -s[p] * pw[n - p], 1);
            s[p] = x;
            add(p, s[p] * pw[p], 0);
            add(p, s[p] * pw[n - p], 1);
        }
        else {
            p = 2 * p + (t - 2);
            int l = 0, r = min(p, n - p);
            while(r - l > 1) {
                int m = (l + r) / 2;
                int h1 = get(p - m, p + m, 0);
                int h2 = get(p - m, p + m, 1);
                h1 *= pw[n - (p - m)];
                h2 *= pw[p + m];
                if(h1 == h2)
                    l = m;
                else
                    r = m;
            }
            cout << (l ? l : -1) << "\n";
        }
    }
    return 0;
}
