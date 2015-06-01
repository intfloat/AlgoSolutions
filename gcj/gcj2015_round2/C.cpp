#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
set<string> read() {
    string s;
    getline(cin, s);
    set<string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, ' ')) {
        if (item.empty() || item == "\n" || item == " " || item == "\t") continue;
        elems.insert(item);
    }
    return elems;
}
int S, T, ptr = 0;
const int INF = INT_MAX / 2;
const int MAX_N = 60000;
int nt[MAX_N], head[MAX_N], pnf[MAX_N], pnt[MAX_N], flow[MAX_N];
vector<int> pv(MAX_N), mn(MAX_N);
vector<bool> visited(MAX_N);
void addedge(int from, int to, int c) {
    nt[ptr] = head[from]; head[from] = ptr; pnf[ptr] = from; pnt[ptr] = to; flow[ptr++] = c;
    nt[ptr] = head[to]; head[to] = ptr; pnf[ptr] = to; pnt[ptr] = from; flow[ptr++] = 0;
}
int maxflow() {
    int res = 0;
    while (true) {
        fill(visited.begin(), visited.end(), false);
        fill(pv.begin(), pv.end(), -1);
        fill(mn.begin(), mn.end(), -1);
        queue<int> q; q.push(S); visited[S] = true; mn[S] = INF;
        while (!q.empty()) {
            int tp = q.front(); q.pop();
            for (int i = head[tp]; i != -1; i = nt[i]) {
                if (flow[i] == 0) continue;
                int to = pnt[i];
                if (visited[to]) continue;
                pv[to] = i; visited[to] = true; q.push(to); mn[to] = min(mn[tp], flow[i]);
            }
        }
        if (mn[T] <= 0) break;
        res += mn[T];
        int cur = pv[T];
        while (cur != -1) {
            flow[cur] -= mn[T]; flow[cur ^ 1] += mn[T];
            cur = pv[pnf[cur]];
        }
    }
    return res;
}
void solve() {
    int N, idx, x, y, res;
    ptr = 0;
    memset(head, -1, sizeof head);
    cin >> N;
    getchar();
    vector<set<string> > st;
    set<string>::iterator it, tt;
    map<string, int> mp;
    FOR(i, N) st.push_back(read());
    int cnt = 0;
    FOR(i, N) {
        for (it = st[i].begin(); it != st[i].end(); ++it) {
            if (mp.find(*it) == mp.end()) mp[*it] = cnt++;
        }
    }
    S = 2 * mp.size(); T = S + 1;
    FOR(i, mp.size()) {
        addedge(2 * i, 2 * i + 1, 1);
    }
    int MX = 123456;
    for (it = st[0].begin(); it != st[0].end(); ++it) {
        idx = mp[*it];
        addedge(S, 2 * idx, MX);
    }
    for (it = st[1].begin(); it != st[1].end(); ++it) {
        idx = mp[*it];
        addedge(2 * idx + 1, T, MX);
    }
    for (int i = 2; i < N; ++i) {
        for (it = st[i].begin(); it != st[i].end(); ++it) {
            for (tt = st[i].begin(); tt != st[i].end(); ++tt) {
                x = mp[*it], y = mp[*tt];
                if (x == y) continue;
                addedge(2 * x + 1, 2 * y, MX);
            }
        }
    }
    res = maxflow();
    cout << res << endl;
    return;
}

int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
