#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 500005;
vector<vector<int> > factors(MAX_N, vector<int>());
vector<int> cnt(MAX_N, 0);
void preprocess() {
    for (int i = 2; i < MAX_N; ++i) {
        if (!factors[i].empty()) continue;
        for (int j = i; j < MAX_N; j += i) factors[j].push_back(i);
    }
    return;
}
vector<int> arr;
vector<bool> ok;
int main() {
    int n, q, x, pos;
    clock_t start = clock();
    preprocess();    
    scanf("%d %d", &n, &q);
    arr.resize(n); ok.resize(n);
    fill(ok.begin(), ok.end(), false);
    FOR(i, n) scanf("%d", &arr[i]);
    int total = 0;
    ll res = 0;
    FOR(i, q) {
        scanf("%d", &pos); --pos;
        x = arr[pos];
        if (factors[x].empty()) {
            assert(x == 1);
            if (!ok[pos]) { res += total; ++total; ++cnt[x]; }
            else {
                --cnt[x]; --total;
                res -= total;
            }
            ok[pos] = !ok[pos];
        }
        else {
            int up = 1 << factors[x].size();            
            int dt = 0;            
            for (int j = 1; j < up; ++j) {
                int val = 1, bits = 0;
                for (int k = 0; k < factors[x].size(); ++k) {
                    if (j & (1 << k)) {
                        val *= factors[x][k];
                        ++bits;
                    }
                }
                if (bits % 2) {
                    if (ok[pos]) --cnt[val];
                    dt += cnt[val];
                    if (!ok[pos]) ++cnt[val];
                }
                else {
                    if (ok[pos]) --cnt[val];
                    dt -= cnt[val];
                    if (!ok[pos]) ++cnt[val];
                }
            }
            if (ok[pos]) { --total; res -= total - dt; }
            else { res += total - dt; ++total; }
            ok[pos] = !ok[pos];
        }
        cout << res << endl;
    }
    return 0;
}
