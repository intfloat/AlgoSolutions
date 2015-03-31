#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const int MAX_N = 600005;
const ll MOD = 1000000007ll;
int main() {
    char s[MAX_N];
    int n, m;
    scanf("%d %d", &n, &m);
    map<int, set<ll> > table;
    map<ll, vector<string> > all;
    FOR(i, n) {
        scanf("%s", s);
        int len = strlen(s);
        ll val = 0;
        FOR(j, len) {
            val = (val * 3 + (s[j] - 'a')) % MOD;
        }
        if (table.find(len) == table.end()) table[len] = set<ll>();
        table[len].insert(val);
        if (all.find(val) == all.end()) all[val] = vector<string>();
        all[val].push_back(string(s));
    }
    vector<ll> number(3);
    FOR(i, m) {
        scanf("%s", s);
        int len = strlen(s);
        if (table.find(len) == table.end()) {
            printf("NO\n");
            continue;
        }
        ll val = 0;
        FOR(j, len) val = (val * 3 + (s[j] - 'a')) % MOD;

        bool ok = false;
        number[0] = 0; number[1] = 1; number[2] = 2;
        for (int j = len - 1; j >= 0; --j) {
            FOR(k, 3) {
                if (k == s[j] - 'a') continue;
                ll cur = (val - number[s[j] - 'a'] + number[k] + MOD) % MOD;
                if (table[len].find(cur) != table[len].end()) {

                    // we need to do further check
                    vector<string>& v = all[cur];                    
                    FOR(p, v.size()) {
                        if (v[p].size() != len) continue;
                        int cnt = 0;
                        FOR(q, len) {
                            cnt += (v[p][q] != s[q]);
                            if (cnt > 1) break;
                        }
                        if (cnt == 1) {
                            printf("YES\n");
                            ok = true;
                            break;
                        }
                    }
                    if (ok) break;
                }
            }            
            FOR(k, 3) number[k] = (3 * number[k]) % MOD;
            if (ok) break;
        }
        if (!ok) printf("NO\n");
    }
    return 0;
}
