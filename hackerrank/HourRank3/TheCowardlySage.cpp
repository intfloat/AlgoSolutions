#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 2005;
int chain_sg[MAX_N], cycle_sg[MAX_N];
inline int get(set<int>& st) {
    FOR(i, MAX_N) {
        if (st.find(i) == st.end()) {
            return i;
        }
    }
    assert(false);
    return -1;
}
void preprocess() {
    chain_sg[1] = 0;
    for (int i = 2; i < MAX_N; ++i) {
        set<int> st;
        st.insert(chain_sg[i - 1]);
        for (int j = 1; i - j - 1 >= j; ++j) {
            st.insert(chain_sg[j] ^ chain_sg[i - j - 1]);
        }
        chain_sg[i] = get(st);
    }
    for (int i = 2; i < MAX_N; ++i) {
        if (chain_sg[i - 1] == 0) {
            cycle_sg[i] = 1;
        }
        else cycle_sg[i] = 0;
    }
}
const int MAX_M = 10000;
int head[MAX_N * 2], pnt[MAX_M], nt[MAX_M];
bool visited[MAX_M];
int n = 0, ptr = 0;
map<pii, int> mp;
inline int get_index(const pii& val) {
    int sz = mp.size();
    if (mp.find(val) == mp.end()) {
        mp[val] = sz;
        return sz;
    }
    else return mp[val];
}
inline void addedge(int from, int to) {
    pnt[ptr] = to; nt[ptr] = head[from]; head[from] = ptr++;
    pnt[ptr] = from; nt[ptr] = head[to]; head[to] = ptr++;
}
vector<int> vs;
bool cycle;
void dfs(int pos) {
    if (!vs.empty() && pos == vs[0]) {
        assert((int)vs.size() >= 2);
        cycle = true;
        return;
    }
    vs.push_back(pos);
    for (int i = head[pos]; i != -1; i = nt[i]) {
        if (visited[i]) continue;
        visited[i] = visited[i ^ 1] = true;
        dfs(pnt[i]);
        return;
    }
}
inline void solve() {
    ptr = 0;
    mp.clear();
    memset(visited, false, sizeof visited);
    memset(head, -1, sizeof head);
    int N, r, a, b;
    scanf("%d", &N);
    FOR(i, N) {
        scanf("%d %d %d", &r, &a, &b);
        int g = __gcd(a, b);
        a /= g; b /= g;
        int u = get_index({r, -1}), v = get_index({a, b});
        addedge(u, v);
    }
    int res = 0;
    n = mp.size();
    FOR(i, n) {
        vs.clear(); cycle = false;
        dfs(i);
        if ((int)vs.size() == 1) continue;
        if (cycle) {
            res ^= cycle_sg[vs.size()];
            continue;
        }
        int cnt = vs.size();
        vs.clear(); cycle = false;
        dfs(i);
        cnt += (int)vs.size() - 1;
        res ^= chain_sg[cnt];
    }
    if (res == 0) {
        printf("Coward\n");
    }
    else {
        printf("Sage\n");
    }
    return;
}
int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
