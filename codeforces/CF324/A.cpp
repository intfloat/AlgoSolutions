#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    if (n == 1 && t == 10) {
        printf("-1\n");
        return 0;
    }
    string res;
    if (t == 10) {
        FOR(i, n - 1) res.push_back('1');
        res.push_back('0');
    }
    else {
        FOR(i, n) res.push_back((char)('0' + t));
    }
    printf("%s\n", res.c_str());
    return 0;
}
