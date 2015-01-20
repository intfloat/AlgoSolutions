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

int get_dis(const string& s1, const string& s2) {    
    assert(s1.size() == s2.size());
    int res = 0;
    FOR(i, s1.size()) res += (s1[i] != s2[i]);
    return res;
}

const int MAX_N = 1005;
int main() {
    int n, m, k, w;
    vector<string> v(MAX_N, "");
    scanf("%d %d %d %d", &n, &m, &k, &w);
    FOR(i, k) {
        string s;
        FOR(j, n) { cin >> s; v[i] += s; }        
    }
    int dis[MAX_N], prev[MAX_N];
    FOR(i, MAX_N) { dis[i] = n * m; prev[i] = -1; }
    bool visited[MAX_N];
    memset(visited, false, sizeof(visited));

    long long res = 0;
    vector<pair<int, int> > ps;
    FOR(i, k) {
        int mn = INT_MAX / 2, pos = -1;
        FOR(j, k) {
            if (!visited[j] && dis[j] < mn) { mn = dis[j]; pos = j; }
        }        
        assert(pos >= 0);
        visited[pos] = true;
        res += dis[pos];
        ps.push_back(make_pair(pos, prev[pos]));
        FOR(j, k) {
            if (!visited[j]) {
                int t = get_dis(v[j], v[pos]) * w;
                if (t < dis[j]) { dis[j] = t; prev[j] = pos; }
            }
        }
    }
    cout << res << endl;
    FOR(i, ps.size()) printf("%d %d\n", ps[i].first + 1, ps[i].second + 1);
    return 0;
}
