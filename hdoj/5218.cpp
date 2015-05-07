#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> numbers(m);
    FOR(i, m) scanf("%d", &numbers[i]);
    sort(numbers.begin(), numbers.end());
    int sz = unique(numbers.begin(), numbers.end()) - numbers.begin();
    numbers.resize(sz);
    vector<bool> prev(1, true), cur;
    for (int len = 2; len <= n; ++len) {
        cur.resize(len);
        // assert(cur.size() == prev.size() + 1);
        fill(cur.begin(), cur.end(), false);
        FOR(i, cur.size()) {
            FOR(j, numbers.size()) {
                if (i == (numbers[j] - 1) % len) continue;
                int pos = (i + len - (numbers[j] % len)) % len;
                // assert(pos < len - 1);
                cur[i] = prev[pos];
                if (cur[i]) break;
            }
        }
        prev = cur;
    }
    printf("%d\n", accumulate(cur.begin(), cur.end(), 0));
    bool fir = true;
    FOR(i, n) {
        if (fir && cur[i]) {
            printf("%d", i + 1);
            fir = false;
        }
        else if (cur[i]) printf(" %d", i + 1);
    }
    printf("\n");
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) solve();
    return 0;
}
