#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9 + 7);
vector<int> num;
bool visited[10];
string s;
int N, K;
map<char, int> mp[10];
ll res = 0;
void dfs(int pos) {
    if (pos == K) {
        ll val = 1ll;
        FOR(i, K) val = (val * mp[num[i]][s[i]]) % MOD;
        res = (res + val) % MOD;
        return;
    }
    FOR(i, N) {
        if (!visited[i]) {
            visited[i] = true;
            num.push_back(i);
            dfs(pos + 1);
            visited[i] = false;
            num.pop_back();
        }
    }
}
int main() {
    char ch;
    cin >> N >> K;
    memset(visited, false, sizeof visited);
    FOR(i, N) FOR(j, 6) {
        cin >> ch;
        ++mp[i][ch];
    }
    cin >> s;
    dfs(0);
    cout << res << endl;
    return 0;
}
