#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, x, y;
    scanf("%d", &n);
    map<int, vector<pii> > mp;
    FOR(i, n) {
        scanf("%d %d", &x, &y);
        mp[y - x].push_back({x, y});
    }
    vector<int> w(n);
    FOR(i, n) scanf("%d", &w[i]);
    vector<pii> res;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        vector<pii>& arr = it->second;
        sort(arr.begin(), arr.end(), greater<pii>());
    }
    map<pii, int> rev;
    FOR(i, n) {
        if (mp.find(w[i]) == mp.end() || mp[w[i]].empty()) {
            printf("NO\n");
            return 0;
        }
        res.push_back(mp[w[i]].back());
        rev[res.back()] = i;
        mp[w[i]].pop_back();
    }
    FOR(i, n) {
        x = res[i].first; y = res[i].second;
        pii p1 = make_pair(x - 1, y);
        pii p2 = make_pair(x, y - 1);
        if (rev.find(p1) != rev.end() && rev[p1] > rev[res[i]]) {
            printf("NO\n");
            return 0;
        }
        if (rev.find(p2) != rev.end() && rev[p2] > rev[res[i]]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    FOR(i, n) {
        printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}
