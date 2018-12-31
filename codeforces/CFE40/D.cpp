#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> bfs(vector<vector<int> >& edges, int src) {
    int n = edges.size();
    vector<int> distance(n, -1);
    queue<int> q;
    q.push(src);
    distance[src] = 0;
    while (!q.empty()) {
        int tp = q.front();
        q.pop();
        for (int i = 0; i < edges[tp].size(); ++i) {
            int to = edges[tp][i];
            if (distance[to] < 0) {
                distance[to] = distance[tp] + 1;
                q.push(to);
            }
        }
    }
    return distance;
}
int main() {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    --s; --t;
    vector<vector<int> > edges(n, vector<int>());
    set<pair<int, int> > st;
    FOR(i, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        st.insert({u, v});
        st.insert({v, u});
    }
    vector<int> dis_from_s = bfs(edges, s);
    vector<int> dis_from_t = bfs(edges, t);
    int dis_st = dis_from_s[t];
    assert(dis_from_s[t] == dis_from_t[s]);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (st.find({i, j}) == st.end()) {
                int min_dis = min(dis_from_s[i] + dis_from_t[j], dis_from_s[j] + dis_from_t[i]) + 1;
                res += (min_dis >= dis_st);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
