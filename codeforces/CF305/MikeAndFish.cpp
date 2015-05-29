#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
vector<point> arr;
const int MAX_N = 200005;
map<int, set<int> > g;
map<point, int> res;
set<int> odd, even;
map<int, set<int> >::iterator it;
vector<int> diff(MAX_N * 2, 0);
vector<int> path;

inline void addedge(int u, int v) {
    g[u].insert(v); g[v].insert(u);
}
inline void deledge(int u, int v) {
    g[u].erase(v); g[v].erase(u);
}
inline void euler(int u) {
    while (!g[u].empty()) {
        int v = *g[u].begin();
        deledge(u, v);
        euler(v);
    }
    path.push_back(u);
}
void solve() {
    if (odd.empty()) {
        for (it = g.begin(); it != g.end(); ++it) {            
            path.clear();
            euler(it->first);            
            for (int i = 1; i < path.size(); ++i) {                
                res[make_pair(path[i - 1], path[i])] = res[make_pair(path[i], path[i - 1])] = i % 2;
                deledge(path[i - 1], path[i]);
            }
        }        
    }
    else {
        int u = *odd.begin(); odd.erase(odd.begin()); even.insert(u);
        int v = *g[u].begin();
        if (odd.find(v) != odd.end()) { odd.erase(v); even.insert(v); }
        else { even.erase(v); odd.insert(v); }
        deledge(u, v);
        solve();
        int c = 1;        
        if (diff[v] == 1) c = 0;        
        res[make_pair(u, v)] = res[make_pair(v, u)] = c;
        if (c == 0) { --diff[u]; --diff[v]; }
        else { ++diff[u]; ++diff[v]; }        
    }
    return;
}
int main() {
    int n, x, y;
    scanf("%d", &n);
    arr.resize(n);
    FOR(i, n) {
        scanf("%d %d", &x, &y);
        --x; --y;
        arr[i] = make_pair(x, y + MAX_N);
        addedge(x, y + MAX_N);
    }    
    for (it = g.begin(); it != g.end(); ++it) {
        if ((it->second).size() % 2) odd.insert(it->first);
        else even.insert(it->first);
    }
    solve();
    const char color[] = {'r', 'b'};
    FOR(i, n) {
        printf("%c", color[res[arr[i]]]);
    }
    printf("\n");
    return 0;
}
