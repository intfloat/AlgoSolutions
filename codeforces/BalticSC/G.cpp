#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char s[100005], mv[100005];
int main() {
    int n, x, len;
    scanf("%d %d", &n, &x);
    scanf("%s", s);
    scanf("%d", &len);
    scanf("%s", mv);
    string res;
    int pos = x - 1;
    res.push_back(s[pos]);
    FOR(i, len) {
        if (mv[i] == 'R') ++pos;
        else --pos;
        res.push_back(s[pos]);
    }
    printf("%s\n", res.c_str());
    return 0;
}
