#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 100005;
char a[MAX_N], b[MAX_N];
inline char get(int i) {
    for (char r = 'a'; r <= 'c'; ++r) {
        if (r != a[i] && r != b[i]) {
            return r;
        }
    }
    assert(false);
    return 'z';
}
int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    scanf("%s %s", a, b);
    vector<int> diff;
    FOR(i, n) {
        if (a[i] != b[i]) diff.push_back(i);
    }
    int mn = (diff.size() + 1) / 2, mx = n;
    if (t < mn || t > mx) {
        printf("-1\n");
        return 0;
    }
    int sz = diff.size();
    string res(n, 'a');
    if (sz % 2) {
        res[diff[0]] = get(diff[0]);
        --t;
    }
    for (int i = sz % 2; i < sz; i += 2) {
        if (t == (sz - i) / 2) {
            --t;
            res[diff[i]] = a[diff[i]];
            res[diff[i + 1]] = b[diff[i + 1]];
        }
        else {
            t -= 2;
            res[diff[i]] = get(diff[i]);
            res[diff[i + 1]] = get(diff[i + 1]);
        }
    }
    FOR(i, n) {
        if (t == 0 && a[i] == b[i]) {
            res[i] = a[i];
         }
         else if (t > 0 && a[i] == b[i]) {
            --t;
            res[i] = get(i);
         }
    }
    assert(t == 0);
    printf("%s\n", res.c_str());
    return 0;
}
