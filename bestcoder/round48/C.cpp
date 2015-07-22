// TLE, 然并卵
#include <vector>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <utility>
#include <ctime>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
vector<int> num;
vector<map<int, int> > pcnt;
map<int, vector<int> > rem;
inline int get(int x, int p) {
    if (p == 0) return 0ll;
    return rem[x][p];
}
inline int total(int low, int up, int x) {
    if (low > up || pcnt[up].find(x) == pcnt[up].end()) {
        return 0;
    }
    if (low == 0 || pcnt[low - 1].find(x) == pcnt[low - 1].end()) {
        return pcnt[up][x];
    }
    return pcnt[up][x] - pcnt[low - 1][x];
}
inline void solve() {
    int n, q;
    scanf("%d %d", &n, &q);
    num.resize(n);
    pcnt.clear(); rem.clear();
    map<int, int> tcnt;
    map<int, int>::iterator it;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        ++tcnt[num[i]];
    }
    for (it = tcnt.begin(); it != tcnt.end(); ++it) {
        rem[it->first].push_back(1);
        ll pv = 1;
        for (int i = 1; i <= it->second; ++i) {
            pv = (pv * it->first) % MOD;
            rem[it->first].push_back(pv);
        }
    }
    int block = int(sqrt(n));
    int sz = n / block + 1;
    vector<vector<ll> > g(sz, vector<ll>(sz, -1));
    // clock_t start = clock();
    // printf("%d %d\n", n / block, n);
    map<int, int> cnt;
    for (int i = 0; i < n; i += block) {
        cnt.clear();
        int val = 0;
        for (int j = i; j < n; ++j) {
            int cc = cnt[num[j]];
            if (j % block == 0 && j > i) {
                if (i == 0) pcnt.push_back(cnt);
                g[i / block][j / block - 1] = val;
            }
            val = (val - get(num[j], cc) + get(num[j], cc + 1)) % MOD;
            if (val < 0) val = (val + MOD) % MOD;
            ++cnt[num[j]];
        }
    }
    // printf("time: %d\n", clock() - start);
    int res = 0;
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        int low = min((a ^ res) % n, (b ^ res) % n);
        int up = max((a ^ res) % n, (b ^ res) % n);
        res = 0;
        cnt.clear();
        if (low / block == up / block) {
            for (int j = low; j <= up; ++j) {
                res = (res - get(num[j], cnt[num[j]]) + get(num[j], 1 + cnt[num[j]])) % MOD;
                if (res < 0) {
                    res = (res + MOD) % MOD;
                }
                ++cnt[num[j]];
            }
            printf("%d\n", res);
            continue;
        }
        while (low % block != 0) {
            ++cnt[num[low]];
            ++low;
        }
        while ((up + 1) % block != 0) {
            ++cnt[num[up]];
            --up;
        }
        int x = low / block, y = up / block;
        if (x <= y) res = g[x][y];
        for (it = cnt.begin(); it != cnt.end(); ++it) {
            int c = total(x, y, it->first);
            res = res - get(it->first, c) + get(it->first, c + it->second);
            res %= MOD;
            if (res < 0) {
                res = (res + MOD) % MOD;
            }
        }
        printf("%d\n", res);
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
