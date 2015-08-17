#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int MAX_N = 405;
const int MAX_M = 330000;
bool reach[405][405];
int n, m;
class SAT {
public:
    int head[MAX_N], ptr;
    vector<int> pnt, nt;
    bool visited[MAX_N];
    int dfn[MAX_N], low[MAX_N], belong[MAX_N], scc, cnt;
    void init() {
        pnt.resize(MAX_M);
        nt.resize(MAX_M);
        memset(head, -1, sizeof head);
        ptr = scc = cnt = 0;
    }
    void addedge(int from, int to) {
        pnt[ptr] = to; nt[ptr] = head[from]; head[from] = ptr++;
    }
    stack<int> st;
    void tarjan(int pos) {
        visited[pos] = true;
        dfn[pos] = low[pos] = cnt++;
        st.push(pos);
        for (int i = head[pos]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (visited[to]) {
                low[pos] = min(low[pos], dfn[to]);
            }
            else {
                tarjan(to);
                low[pos] = min(low[pos], low[to]);
            }
        }
        if (dfn[pos] == low[pos]) {
            while (st.top() != pos) {
                belong[st.top()] = scc;
                dfn[st.top()] = low[st.top()] = MAX_N;
                st.pop();
            }
            belong[pos] = scc++;
            dfn[pos] = low[pos] = MAX_N;
            st.pop();
        }
    }
    bool check() {
        memset(visited, false, sizeof visited);
        for (int i = 0; i < 2 * n; ++i) {
            if (!visited[i]) {
                tarjan(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (belong[i * 2] == belong[i * 2 + 1]) {
                return false;
            }
        }
        return true;
    }
    void bfs() {
        memset(reach, false, sizeof reach);
        FOR(i, 2 * n) {
            reach[i][i] = true;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int tp = q.front(); q.pop();
                for (int j = head[tp]; j != -1; j = nt[j]) {
                    int to = pnt[j];
                    if (!reach[i][to]) {
                        reach[i][to] = true;
                        q.push(to);
                    }
                }
            }
        }
        return;
    }
};
char alpha[30], cur[205];
inline int conv(char c) {
    return (alpha[c - 'a'] == 'C');
}
SAT sol;
struct Edge {
    int from, to;
    Edge(int p1, char c1, int p2, char c2) {
        from = p1 * 2 + (c1 == 'C');
        to = p2 * 2 + (c2 == 'C');
    }
};
int vs[30], cs[30];
int mnv = -1, mnc = -1;
inline void preprocess() {
    memset(vs, -1, sizeof vs);
    memset(cs, -1, sizeof cs);
    int len = strlen(alpha);
    FOR(i, len) {
        if (alpha[i] == 'V' && mnv == -1) mnv = i;
        if (alpha[i] == 'C' && mnc == -1) mnc = i;
        for (int j = i + 1; j < len; ++j) {
            if (alpha[j] == 'V') { vs[i] = j; break; }
        }
        for (int j = i + 1; j < len; ++j) {
            if (alpha[j] == 'C') { cs[i] = j; break; }
        }
    }
}
int main() {
    scanf("%s", alpha);
    scanf("%d %d", &n, &m);
    vector<Edge> g;
    int p1, p2;
    char c1, c2;
    FOR(i, m) {
        scanf("%d %c %d %c", &p1, &c1, &p2, &c2);
        --p1; --p2;
        g.push_back(Edge(p1, c1, p2, c2));
    }
    scanf("%s", cur);
    preprocess();
    int candc[205], candv[205];
    for (int i = n - 1; i >= -1; --i) {
        if (i + 1 < n) { candc[i + 1] = cs[cur[i + 1] - 'a']; candv[i + 1] = vs[cur[i + 1] - 'a']; }
        for (int j = i + 2; j < n; ++j) {
            candc[j] = mnc;
            candv[j] = mnv;
        }
        sol.init();
        for (int j = 0; j <= i; ++j) {
            if (conv(cur[j])) sol.addedge(j * 2, j * 2 + 1);
            else sol.addedge(j * 2 + 1, j * 2);
        }
        FOR(j, g.size()) {
            sol.addedge(g[j].from, g[j].to);
            sol.addedge(g[j].to ^ 1, g[j].from ^ 1);
        }
        for (int j = i + 1; j < n; ++j) {
            if (candc[j] == -1) sol.addedge(j * 2 + 1, j * 2);
            if (candv[j] == -1) sol.addedge(j * 2, j * 2 + 1);
        }
        if (!sol.check()) continue;
        sol.bfs();
        string res;
        int idx;
        vector<bool> ok(2 * n, true);
        for (int j = 0; j <= i; ++j) {
            res.push_back(cur[j]);
            idx = j * 2 + (alpha[cur[j] - 'a'] == 'C');
            FOR(k, 2 * n) {
                if (reach[idx][k]) ok[k ^ 1] = false;
            }
        }
        for (int j = i + 1; j < n; ++j) {
            if (reach[j * 2][j * 2 + 1] || !ok[j * 2]) {
                idx = j * 2 + 1;
                res.push_back('a' + candc[j]);
            }
            else if (reach[j * 2 + 1][j * 2] || !ok[j * 2 + 1]) {
                idx = j * 2;
                res.push_back('a' + candv[j]);
            }
            else if (candc[j] < candv[j]) {
                idx = j * 2 + 1; res.push_back('a' + candc[j]);
            }
            else { idx = j * 2; res.push_back('a' + candv[j]); }
            FOR(k, 2 * n) {
                if (reach[idx][k]) ok[k ^ 1] = false;
            }
        }
        printf("%s\n", res.c_str());
        return 0;
    }
    printf("-1\n");
    return 0;
}
