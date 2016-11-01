#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
map<pii, int> mp, pos_mp;
int calc(int l, int w, int h) {
    auto it = mp.find({l, w});
    if (it == mp.end()) return -1;
    else {
        return min(l, min(w, h + it->second));
    }
}
void madd(int l, int w, int h, int idx) {
    pii val = {l, w};
    if (mp.find(val) == mp.end() || mp[val] < h) {
        mp[val] = h;
        pos_mp[val] = idx;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n), c(n);
    int one_mx = -1, one_pos = -1;
    FOR(i, n) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        if (c[i] > a[i]) swap(a[i], c[i]);
        if (c[i] > b[i]) swap(b[i], c[i]);
        int cur = c[i];
        if (cur > one_mx) {
            one_mx = cur;
            one_pos = i;
        }
    }
    int two_mx = -1;
    pii two_pos;
    FOR(i, n) {
        int cur = calc(a[i], b[i], c[i]);
        if (cur > two_mx) {
            two_mx = cur;
            two_pos = {pos_mp[{a[i], b[i]}], i};
        }
        madd(a[i], b[i], c[i], i);
        madd(b[i], a[i], c[i], i);
        madd(a[i], c[i], b[i], i);
        madd(c[i], a[i], b[i], i);
        madd(c[i], b[i], a[i], i);
        madd(b[i], c[i], a[i], i);
    }
    if (one_mx > two_mx) {
        printf("1\n%d\n", one_pos + 1);
    } else {
        printf("2\n%d %d\n", two_pos.first + 1, two_pos.second + 1);
    }
    return 0;
}
