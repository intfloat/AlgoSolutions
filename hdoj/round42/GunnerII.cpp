#include <stdio.h>
#include <map>
#include <set>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int n, m, h, shot;
map<int, set<int> > mp;
void solve() {
    mp.clear();
    FOR(i, n) {
        scanf("%d", &h);
        if (mp.find(h) == mp.end()) {
            mp[h] = set<int>();
        }
        mp[h].insert(i + 1);
    }
    FOR(i, m) {
        scanf("%d", &shot);
        if (mp.find(shot) == mp.end() || mp[shot].empty()) {
            printf("-1\n");
        }
        else {
            set<int>& s = mp[shot];
            printf("%d\n", *s.begin());
            s.erase(s.begin());
        }
    }
    return;
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) solve();
    return 0;
}
