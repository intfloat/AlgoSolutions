#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
struct Node {
    int from, to, idx;
    ll cost;
    Node(int _f, int _t, ll _c, int _x): from(_f), to(_t), cost(_c), idx(_x) {}
};
const int MAX_N = 300050;
int head[MAX_N], nt[MAX_N * 2], pnt[MAX_N * 2], wei[MAX_N * 2];
int ptr;
void addedge(int u, int v, int w) {
    nt[ptr] = head[u]; head[u] = ptr; pnt[ptr] = v; wei[ptr++] = w;
    nt[ptr] = head[v]; head[v] = ptr; pnt[ptr] = u; wei[ptr++] = w;
}
bool operator<(const Node& a, const Node& b) {
    if (a.cost != b.cost) return a.cost > b.cost;
    else return wei[a.idx] > wei[b.idx];
}
int main() {
    int n, m, u, v, to, root, w;
    ptr = 0;
    memset(head, -1, sizeof head);
    scanf("%d %d", &n, &m);
    FOR(i, m) {
        scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        addedge(u, v, w);
    }
    scanf("%d", &root);
    --root;
    vector<bool> visited(n, false);
    priority_queue<Node> q;
    q.push(Node(root, root, 0, -1));
    vector<ll> dis(n);
    ll total = 0;
    vector<int> res;
    FOR(i, n) {
        while (true) {
            Node node = q.top(); q.pop();
            if (visited[node.to]) continue;
            // cout << "DEBUG: " << node.cost << " " << node.to << endl;
            if (node.idx >= 0) {
                res.push_back(node.idx / 2);
                total += wei[node.idx];
            }
            v = node.to;
            dis[v] = node.cost;
            visited[v] = true;
            for (int j = head[v]; j != -1; j = nt[j]) {
                to = pnt[j];
                if (visited[to]) continue;
                q.push(Node(v, to, dis[v] + wei[j], j));
            }
            break;
        }
    }
    cout << total << endl;
    FOR(i, n - 1) printf("%d ", res[i] + 1);
    printf("\n");
    return 0;
}
