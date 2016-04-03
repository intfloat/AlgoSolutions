#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
int main() {
    int F, I, T, kitten = 0;
    cin >> F >> I >> T;
    vector<int> it(I, 0);
    FOR(i, F) {
        string s;
        cin >> s;
        FOR(i, I) {
            if (s[i] == 'Y') {
                ++it[i];
            }
        }
    }
    int r = 0;
    FOR(i, I) {
        r += (it[i] >= T);
    }
    printf("%d\n", r);
    return 0;
}
