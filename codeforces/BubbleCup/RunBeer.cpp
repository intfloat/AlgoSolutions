#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> point;
const int MAX_N = (int)(1e5 + 5);
const int MAX_M = MAX_N * 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], wei[MAX_M], ptr;
map<pair<int, int>, int> mp;
inline void addedge(int x, int y, int w) {
    mp[{x, y}] = w; mp[{y, x}] = w;
    pnt[ptr] = y; nt[ptr] = head[x]; wei[ptr] = w; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; wei[ptr] = w; head[y] = ptr++;
}
int zero[MAX_N], pv[MAX_N];
inline void bfs(int start) {
    queue<int> q;
    memset(pv, -1, sizeof pv);
    memset(zero, -1, sizeof zero);
    zero[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        for (int i = head[tp]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (wei[i] != 0 || zero[to] >= 0) continue;
            zero[to] = zero[tp] + 1;
            pv[to] = tp;
            q.push(to);
        }
    }
}
int step[MAX_N], pv2[MAX_N], belong[MAX_N];
int main() {
    int n, m, x, y, w;
    scanf("%d %d", &n, &m);
    memset(head, -1, sizeof head);
    ptr = 0;
    FOR(i, m) {
        scanf("%d %d %d", &x, &y, &w);
        addedge(x, y, w);
    }
    bfs(n - 1);
    point res = make_tuple(MAX_N, -1, -1);
    queue<int> q;
    memset(step, -1, sizeof step);
    memset(pv2, -1, sizeof pv2);
    memset(belong, -1, sizeof belong);
    q.push(0); step[0] = 0; belong[0] = 0;
    pair<int, int> state[MAX_N];
    int idx = -1;
    while (!q.empty()) {
        vector<pair<int, int> > arr;
        set<int> vs;
        int up = q.size();
        for (int j = 0; j < up; ++j) {
            int tp = q.front(); q.pop();
            if (zero[tp] >= 0) {
                auto opt = make_tuple(step[tp], belong[tp], zero[tp]);
                if (opt < res) {
                    res = opt;
                    idx = tp;
                }
            }
            for (int i = head[tp]; i != -1; i = nt[i]) {
                int to = pnt[i];
                auto cur = make_pair(wei[i], belong[tp]);
                if (step[to] < 0) {
                    step[to] = step[tp] + 1;
                    pv2[to] = tp;
                    state[to] = cur;
                    vs.insert(to);
                    q.push(to);
                }
                else if (step[to] == step[tp] + 1 && cur < state[to]) {
                    state[to] = cur;
                    pv2[to] = tp;
                }
            }
        }
        for (auto it = vs.begin(); it != vs.end(); ++it) {
            arr.push_back(state[*it]);
        }
        sort(arr.begin(), arr.end());
        arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
        for (auto it = vs.begin(); it != vs.end(); ++it) {
            belong[*it] = lower_bound(arr.begin(), arr.end(), state[*it]) - arr.begin();
        }
    }
    vector<int> path;
    int tmp = idx;
    while (idx >= 0) {
        path.push_back(idx);
        idx = pv2[idx];
    }
    reverse(path.begin(), path.end());
    idx = pv[tmp];
    while (idx >= 0) {
        path.push_back(idx);
        idx = pv[idx];
    }
    string distance;
    idx = tmp;
    while (pv2[idx] >= 0) {
        char ch = (char)('0' + mp[{pv2[idx], idx}]);
        distance.push_back(ch);
        idx = pv2[idx];
    }
    if (distance.empty()) distance.push_back('0');
    printf("%s\n", distance.c_str());
    printf("%d\n", path.size());
    for (int i = 0; i < path.size(); ++i) {
        printf("%d ", path[i]);
    }
    printf("\n");
    return 0;
}
