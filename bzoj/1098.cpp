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

const int MAX_N = 100005;
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    map<int, set<int> > g;
    set<int> v;
    FOR(i, N) v.insert(i + 1);
    FOR(i, M) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (g.find(a) == g.end()) {
            set<int> s; s.insert(b); g[a] = s;
        }
        else g[a].insert(b);
        if (g.find(b) == g.end()) {
            set<int> s; s.insert(a); g[b] = s;
        }
        else g[b].insert(a);
    }
    vector<int> res;
    bool visited[MAX_N];
    memset(visited, false, sizeof(visited));
    for (int i = N; i >= 1; --i) {
        if (visited[i]) continue;
        int cnt = 0;
        queue<int> q; q.push(i); visited[i] = true;
        v.erase(v.find(i));
        vector<int> tmp;
        while (!q.empty()) {
            int tp = q.front(); q.pop();
            ++cnt;
            set<int>::iterator it = v.begin();
            for (; it != v.end(); ++it) {
                if (!visited[*it] && g[tp].find(*it) == g[tp].end()) {
                    visited[*it] = true;
                    q.push(*it);
                    tmp.push_back(*it);
                }
            }
            FOR(j, tmp.size()) v.erase(v.find(tmp[j]));
            tmp.clear();
        }
        res.push_back(cnt);
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    FOR(i, res.size()) cout << res[i] << " ";
    cout << endl;
    return 0;
}
