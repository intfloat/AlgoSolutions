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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 10005;
int main() {
    bool prev[MAX_N], cur[MAX_N];
    int N;
    while (cin >> N) {
        memset(prev, false, sizeof(prev));
        memset(cur, false, sizeof(cur));
        vector<int> ns;
        int t, total;
        FOR(i, N) { cin >> t; ns.push_back(t); }
        total = accumulate(ns.begin(), ns.end(), 0);
        prev[0] = cur[0] = true;
        prev[ns[0]] = cur[ns[0]] = true;
        for (int i = 1; i < ns.size(); ++i) {
            FOR(j, total + 1) {
                if (!prev[j]) continue;
                cur[j + ns[i]] = true;
                cur[abs(j - ns[i])] = true;
            }
            FOR(j, total + 1) prev[j] = cur[j];
        }
        vector<int> res;        
        for (t = 0; t <= total; ++t) {
            if (!cur[t]) res.push_back(t);
        }
        cout << res.size() << endl;
        if (!res.empty()) {        
            cout << res[0];
            for (int i = 1; i < res.size(); ++i) cout << " " << res[i];
            cout << endl;
        }  
    }
    return 0;
}