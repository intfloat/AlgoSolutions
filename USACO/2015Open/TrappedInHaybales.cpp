#include <stdio.h>
#include <algorithm>
#include <utility>
#include <cassert>
#include <vector>
#include <set>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
int main() {
    freopen("trapped.in", "r", stdin);
    freopen("trapped.out", "w", stdout);
    int N;
    scanf("%d", &N);
    vector<pair<int, int> > bales(N);
    vector<int> pos(N);
    FOR(i, N) {
        // <position, size>
        scanf("%d %d", &bales[i].second, &bales[i].first);
        pos[i] = bales[i].first;
    }
    sort(pos.begin(), pos.end());
    sort(bales.begin(), bales.end(), [](const point& a, const point& b) { return a.second > b.second; } );    
    vector<vector<bool> > trapped(N, vector<bool>(2, false));
    set<point> s;
    set<point>::iterator it, t;
    FOR(i, bales.size()) {
        s.insert(bales[i]);        
        it = s.find(bales[i]);
        point cur = *it;
        int p = lower_bound(pos.begin(), pos.end(), cur.first) - pos.begin();        
        if (it != s.begin()) {
            t = it; --t;
            point prev = *t;
            int idx = lower_bound(pos.begin(), pos.end(), prev.first) - pos.begin();            
            if (trapped[idx][1]) trapped[p][0] = true;
            else if (pos[p] - pos[idx] <= min(cur.second, prev.second)) {
                trapped[idx][1] = trapped[p][0] = true;
            }
        }
        t = it; ++t;
        if (t != s.end()) {            
            point nt = *t;
            int idx = lower_bound(pos.begin(), pos.end(), nt.first) - pos.begin();     
            if (trapped[idx][0]) trapped[p][1] = true;
            else if (pos[idx] - pos[p] <= min(cur.second, nt.second)) {
                trapped[idx][0] = trapped[p][1] = true;
            }
        }
    }    
    int res = 0;
    FOR(i, N - 1) {
        if (trapped[i][1]) res += pos[i + 1] - pos[i];
    }
    printf("%d\n", res);
    return 0;
}
