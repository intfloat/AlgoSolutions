#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char s[550][550];
inline char rev(char c) {
    if (c == '*') return '+';
    else return '*';
}
int main() {
    int n;
    cin >> n;
    s[0][0] = '+';
    int x = 1;
    FOR(i, n) {
        FOR(r, x) FOR(c, x) s[r][c + x] = s[r][c];
        FOR(r, x) FOR(c, x) s[r + x][c] = rev(s[r][c]);
        FOR(r, x) FOR(c, x) s[r + x][c + x] = s[r][c];
        x *= 2;
    }
    FOR(i, x) s[i][x] = '\0';
    FOR(i, x) {
        printf("%s\n", s[i]);
    }
    return 0;
}
