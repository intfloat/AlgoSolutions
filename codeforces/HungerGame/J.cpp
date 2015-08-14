#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000005;
const int MAX_M = MAX_N * 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], ptr;
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
int tson[MAX_N], mson[MAX_N], n;
bool visited[MAX_N], flag[MAX_N];
vector<int> arr;
int dfs(int pos, int fa) {
    arr.push_back(pos);
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (fa == to || visited[to]) {
            continue;
        }
        int cur = dfs(to, pos);
        mson[pos] = max(mson[pos], cur);
        tson[pos] += cur;
    }
    ++tson[pos];
    mson[pos] = max(mson[pos], n - tson[pos]);
    return tson[pos];
}
int main() {
    int x, y, val;
    scanf("%d", &n);
    ptr = 0;
    memset(head, -1, sizeof head);
    memset(visited, false, sizeof visited);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        addedge(x, y);
    }
    int top = 1;
    while (true) {
        arr.clear();
        memset(tson, 0, sizeof tson);
        memset(mson, 0, sizeof mson);
        dfs(top, -1);
        int mx = MAX_N, idx = -1;
        for (int i = 0; i < arr.size(); ++i) {
            flag[arr[i]] = false;
            if (mson[arr[i]] < mx) {
                mx = mson[arr[i]];
                idx = arr[i];
            }
        }
        cout << idx << endl;
        fflush(stdout);
        cin >> val;
        if (val == 0) return 0;
        visited[idx] = true;
        top = val;
        arr.clear();

        n = 0;
        queue<int> q;
        q.push(top);
        flag[top] = true;
        while (!q.empty()) {
            int tp = q.front(); q.pop(); ++n;
            for (int i = head[tp]; i != -1; i = nt[i]) {
                int to = pnt[i];
                if (visited[to] || flag[to]) continue;
                q.push(to);
                flag[to] = true;
            }
        }
    }
    return 0;
}
