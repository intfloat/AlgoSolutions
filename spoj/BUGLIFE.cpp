#include <stdio.h>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
const int MAX_N = 4005;
const int MAX_M = 4000005;
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
};
int main() {
    SAT sol;
    int T, x, y;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Scenario #%d:\n", i + 1);
        scanf("%d %d", &n, &m);
        sol.init();
        for (int j = 0; j < m; ++j) {
            scanf("%d %d", &x, &y);
            --x; --y;
            sol.addedge(2 * x, 2 * y + 1);
            sol.addedge(2 * y, 2 * x + 1);
            sol.addedge(2 * x + 1, 2 * y);
            sol.addedge(2 * y + 1, 2 * x);
        }
        if (sol.check()) {
            printf("No suspicious bugs found!\n");
        }
        else {
            printf("Suspicious bugs found!\n");
        }
    }
    return 0;
}
