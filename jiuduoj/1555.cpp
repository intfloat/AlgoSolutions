#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const ll MOD = static_cast<ll>(1e13 + 9);

int main() {
    string s;
    vector<ll> hash[2];
    set<ll> res;
    set<ll> values;
    while (cin >> s) {        
        int len = s.size();
        hash[0].resize(len); hash[1].resize(len);
        fill(hash[0].begin(), hash[0].end(), 0);
        int cnt = 0;
        for (int i = 1; 2 * i <= len; ++i) {
            values.clear(); res.clear();
            int pos = len - i;
            for (int j = pos; j > len - 2 * i; --j) {
                hash[1][j] = (hash[0][j] * 26 + (s[j + i - 1] - 'a')) % MOD;
            }
            for (int j = len - 2 * i; j >= 0; --j) {
                values.insert(hash[1][j + i]);                
                hash[1][j] = (hash[0][j] * 26 + (s[j + i - 1] - 'a')) % MOD;
                if (values.find(hash[1][j]) != values.end() && res.find(hash[1][j]) == res.end()) {
                    res.insert(hash[1][j]);
                }
            }
            copy(hash[1].begin(), hash[1].end(), hash[0].begin());
            cnt += res.size();
        }
        cout << cnt << endl;
    }
    return 0;
}
