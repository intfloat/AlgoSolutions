#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MOD = 1000000007;
const int RND = 23333333;
typedef long long ll;

ll hash_str(const string& val) {
    ll res = 0;
    FOR(i, val.size()) {
        res = (res * RND + val[i] - 'a') % MOD;
    }
    return res;
}

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string s;
    cin >> s;
    int N;
    cin >> N;
    vector<string> patterns(N);
    FOR(i, N) cin >> patterns[i];
    map<int, map<ll, vector<string> > > tables;
    map<int, map<ll, vector<string> > >::iterator it;
    FOR(i, N) {
        ll val = hash_str(patterns[i]);
        int len = patterns[i].size();
        if (tables.find(len) == tables.end()) {
            tables[len] = map<ll, vector<string> >();            
        }
        tables[len][val].push_back(patterns[i]);
    }

    vector<ll> multiply(1, 1), arr(1, 0);
    string res;
    for (int i = 0; i < s.size(); ++i) {
        int cur = s[i] - 'a';
        res += s[i];
        multiply.push_back((multiply.back() * RND) % MOD);
        arr.push_back((arr.back() * RND + cur) % MOD);
        int tlen = -1;
        for (it = tables.begin(); it != tables.end(); ++it) {
            if (it->first > arr.size() - 1) continue;
            ll val = arr.back() - (arr[arr.size() - 1 - it->first] * multiply[it->first]) % MOD;
            val = (val + MOD) % MOD;
            map<ll, vector<string> >& mp = it->second;
            if (mp.find(val) != mp.end()) {                                
                vector<string>& vs = mp[val];               
                FOR(j, vs.size()) {
                    if (vs[j] == res.substr(res.size() - it->first)) {
                        tlen = it->first;
                        break;
                    }
                }
                if (tlen != -1) break;
            }

        }
        if (tlen > 0) {            
            multiply.resize(multiply.size() - tlen);
            arr.resize(arr.size() - tlen);            
            assert(res.size() >= tlen);
            res.resize(res.size() - tlen);
        }        
    }
    cout << res << endl;
    return 0;
}
