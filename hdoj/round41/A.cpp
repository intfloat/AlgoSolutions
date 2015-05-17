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
typedef long long ll;
void solve() {
    set<pair<int, int> > arr;
    string s;
    FOR(i, 5) {
        cin >> s;
        pair<int, int> t;
        t.first = s[0] - 'A';
        if (s.size() == 2) t.second = s[1] - '0';
        else t.second = (s[1] - '0') * 10 + (s[2] - '0');
        arr.insert(t);
    }    
    int res = 5;
    FOR(i, 4) for (int j = 1; j <= 10; ++j) {
        int cnt = 0;
        FOR(k, 5) {
            int to = (j + k);
            if (to > 13) to -= 13;
            if (arr.find(make_pair(i, to)) == arr.end()) ++cnt;
        }
        res = min(res, cnt);
    }
    cout << res << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    FOR(tt, T) solve();    
    return 0;
}
