#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    string g[8];
    FOR(i, 8) cin >> g[i];
    int white = 8, black = 0;
    FOR(j, 8) {
        FOR(i, 8) {
            if (g[i][j] == 'W') {
                white = min(white, i);
                break;
            }
            else if (g[i][j] == 'B') break;
        }
    }
    FOR(j, 8) {
        for (int i = 7; i >= 0; --i) {
            if (g[i][j] == 'B') {
                black = max(black, i);
                break;
            }
            else if (g[i][j] == 'W') break;
        }
    }
    black = 7 - black;
    if (white <= black) printf("A\n");
    else printf("B\n");
    return 0;
}
