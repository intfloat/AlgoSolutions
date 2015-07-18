#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
char s[3200000];
inline void solve() {
    scanf("%s", s);
    int sz = strlen(s);
    int ptr = -1;
    FOR(i, sz) {
        if (s[i] == 'w') {
            ptr = i + 1;
            break;
        }
        else if (s[i] == 'v' && i > 0 && s[i - 1] == 'v') {
            ptr = i + 1;
            break;
        }
    }
    if (ptr < 0) {
        printf("No\n");
        return;
    }
    int cnt = 0;
    for (int i = ptr; i < sz; ++i) {
        if (cnt == 0 && s[i] == 'y') {
            cnt = 1;
        }
        else if (cnt == 1 && s[i] == 'h') {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
    return;
}
int main() {
    int T;
    cin >> T;
    FOR(i, T) {
        solve();
    }
    return 0;
}
