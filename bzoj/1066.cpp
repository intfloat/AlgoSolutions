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
using namespace std;

const int MAX_N = 810;
const int MAX_E = MAX_N * 20;
const int S = 804;
const int T = 805;

class MaxFlow {
public:
    int head[MAX_N], flow[MAX_E], next[MAX_E], pnt[MAX_E];
    int cnt, to[MAX_N], mn[MAX_N], from[MAX_E];
    void addedge(int a, int b, int w) {
        assert(cnt < MAX_E);
        // cout << a << " " << b << " " << w << endl;
        from[cnt] = a; pnt[cnt] = b; next[cnt] = head[a]; flow[cnt] = w; head[a] = cnt++;       
        from[cnt] = b; pnt[cnt] = a; next[cnt] = head[b]; flow[cnt] = 0; head[b] = cnt++;
    }

    int maxflow() {
        // cout << "cnt: " << cnt << endl;
        int res = 0;
        bool visited[MAX_N];
        while (true) {
            memset(visited, false, sizeof(visited));
            queue<int> q;
            q.push(S); visited[S] = true; to[S] = -1; mn[S] = INT_MAX / 2;
            while (!q.empty()) {
                int u = q.front(); q.pop();     
                // cout << "u: " << u << " head pnt: " << pnt[head[u]] << endl;
                for (int pos = head[u]; pos >= 0; pos = next[pos]) {                    
                    int v = pnt[pos];
                    // cout << "u: " << u << " v: " << v << endl;
                    if (flow[pos] <= 0) continue;
                    // cout << "tag" << endl;
                    if (visited[v]) continue;
                    // cout << "here" << endl;
                    visited[v] = true;
                    q.push(v); to[v] = pos;
                    mn[v] = min(mn[u], flow[pos]);
                }
            }
            if (!visited[T]) break;
            int cur = to[T];
            res += mn[T];
            assert(mn[T] > 0);
            while (cur >= 0) {
                // cout << "cur: " << cur << " from: " << from[cur] << "res: " << res << endl;
                flow[cur] -= mn[T];
                flow[cur^1] += mn[T];
                cur = to[from[cur]];
            }
        }   
        return res;
    }

    MaxFlow(): cnt(0) {
        for (int i = 0; i < MAX_N; ++i) head[i] = -1;       
    }
};
int main() {
    int row, col, d;
    MaxFlow net;
    cin >> row >> col >> d;
    string h[25], liz[25];
    for (int i = 0; i < row; ++i) cin >> h[i];
    for (int i = 0; i < row; ++i) cin >> liz[i];

    int total = 0;
    for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) {     
        if (h[i][j] == '0') continue;   
        int p1 = i * col + j;
        if (h[i][j] > '0') {
            net.addedge(p1 * 2, p1 * 2 + 1, h[i][j] - '0');
        }
        if (liz[i][j] == 'L') {
            ++total;
            net.addedge(S, p1 * 2, 1);          
        }           
        bool flag = false;
        for (int r = -d; r <= d; ++r)
        for (int c = -d; c <= d; ++c) {
            int rp = i + r; int rc = j + c;
            int dis = abs(r) + abs(c);
            if (dis > d) continue;
            if (rp < 0 || rp >= row || rc < 0 || rc >= col) {
                // avoid inserting too much edge
                if (!flag) {                    
                    net.addedge(p1 * 2 + 1, T, 500); 
                    flag = true; 
                }
                continue;
            }
            if (h[rp][rc] == '0') continue;
            int p2 = rp * col + rc;
            if (p1 >= p2) continue;
            // if (liz[i][j] == 'L' && liz[r][c] == 'L') continue;
            net.addedge(p1 * 2 + 1, p2 * 2, 500);
            net.addedge(p2 * 2 + 1, p1 * 2, 500);
        }
    }
    int res = net.maxflow();
    // cout << "total: " << total << endl;
    // cout << "maxflow: " << res << endl;
    cout << (total - res) << endl;
    return 0;
}
