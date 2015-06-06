#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 100005;
const ll MOD = 1000000007;
char s[MAX_N];
ll dp[MAX_N][2];
vector<int> tag;
vector<ll> pw;
void preprocess() {
    pw.resize(MAX_N);
    pw[0] = 1;
    FOR(i, MAX_N - 1) pw[i + 1] = (pw[i] * 26) % MOD;
    return;
}
map<pair<char, int>, ll> mp;
ll work(int ps, int ptag) {
    bool visited[26];
    memset(visited, false, sizeof visited);
    pair<char, int> tt = make_pair(s[ps + 1], ptag);
    if (mp.find(tt) != mp.end()) return mp[tt];
    ll ret = 0;
    int cc = 0;
    if (ptag < 0) {
        FOR(i, ps + 1) visited[s[i] - 'a'] = true;
        cc = accumulate(visited, visited + 26, 0);
        mp[tt] = cc;
        return cc;
    }
    cc = 26;
    for (int i = tag[ptag] + 1; i <= ps; ++i) {
        if (!visited[s[i] - 'a']) {
            visited[s[i] - 'a'] = true; --cc;
            ret = (ret + pw[ptag + 1]) % MOD;
        }
    }
    for (int i = tag[ptag]; ; --i) {
        if (!cc) break;
        if (!visited[s[i] - 'a']) {
            visited[s[i] - 'a'] = true; --cc;
            ret = (ret + work(i - 1, ptag - 1)) % MOD;
        }
    }
    mp[tt] = ret;
    return ret;
}
void solve() {
    scanf("%s", s);
    mp.clear();
    int sz = strlen(s);
    tag.clear();
    set<char> st;
    int k = 0;
    FOR(i, sz) {
        st.insert(s[i]);
        if (st.size() == 26) {
            st.clear();
            ++k;
            tag.push_back(i);
        }
    }
    ++k;
    ll res = pw[k];
    ll cnt = 0;
    if (tag.size() == 0) cnt = st.size();
    else cnt = work(sz - 1, tag.size() - 1);
    res = (res - cnt + MOD) % MOD;
    cout << k << " " << res << endl;
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    preprocess();
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
