#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 10005;
char s[MAX_N];
int main() {
    scanf("%s", s + 1);
    int m, l, r, k;
    scanf("%d", &m);
    FOR(i, m) {
        scanf("%d %d %d", &l, &r, &k);
        k %= (r - l + 1);
        if (k > 0) {
            reverse(s + l, s + r - k + 1);
            reverse(s + r - k + 1, s + r + 1);
            reverse(s + l, s + r + 1);
        }
    }
    printf("%s\n", s + 1);
    return 0;
}
