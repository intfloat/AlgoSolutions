#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
char s[1000005];
int main() {
    int n;
    scanf("%d %s", &n, s);
    int ws = 0, vs = 0;
    string val;
    FOR(i, n) {
        if (s[i] == 'w') {
            ++ws;
            val.push_back('v');
            val.push_back('v');
        }
        else val.push_back(s[i]);
    }
    for (int i = 0; i + 1 < val.size(); ++i) {
        if (val[i] == 'v' && val[i + 1] == 'v') {
            ++vs;
            ++i;
        }
    }
    printf("%d %d\n", val.size() - vs, n + ws);
    return 0;
}
