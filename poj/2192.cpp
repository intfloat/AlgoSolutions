#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
using namespace std;
char s1[205], s2[205], t[405];
map<pair<int, int>, bool> dp;
bool check(int p1, int p2) {
    if (p1 == 0 && p2 == 0) {
        return true;
    }
    pair<int, int> cur = make_pair(p1, p2);
    if (dp.find(cur) != dp.end()) {
        return dp[cur];
    }
    bool res = false;
    if (p1 - 1 >= 0 && s1[p1 - 1] == t[p1 + p2 - 1]) {
        res = res || check(p1 - 1, p2);
    }
    if (!res && p2 - 1 >= 0 && s2[p2 - 1] == t[p1 + p2 - 1]) {
        res = res || check(p1, p2 - 1);
    }
    dp[cur] = res;
    return res;
}
inline void solve() {
    scanf("%s %s %s", s1, s2, t);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    dp.clear();
    if (check(n1, n2)) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Data set %d: ", i + 1);
        solve();
    }
    return 0;
}
