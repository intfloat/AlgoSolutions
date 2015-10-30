#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 20005;
const int MAX_M = MAX_N * 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], ptr = 0;
char ch[MAX_M];
inline void addedge(int x, int y, char c) {
    pnt[ptr] = y; nt[ptr] = head[x]; ch[ptr] = c; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; ch[ptr] = c; head[y] = ptr++;
}
int main() {
    memset(head, -1, sizeof head);
    int n, x, y;
    char c;
    scanf("%d", &n);
    FOR(i, n - 1) {
        scanf("%d %d %c", &x, &y, &c);
        --x; --y;
        addedge(x, y, c);
    }
    vector<int> res(n, -1);
    char att[MAX_N];
    bool visited[MAX_N];
    int q[MAX_N];
    FOR(i, n) {
        string val;
        int l = 0, r = 0;
        FOR(j, n) att[j] = 0;
        FOR(j, n) visited[j] = false;
        q[r++] = i; visited[i] = true; res[i] = i;
        int step = -1;
        while (l < r) {
            int sz = r - l;
            bool fir = true;
            while (sz--) {
                int tp = q[l++];
                if (step < 0 || att[tp] == val[step]) {
                    for (int k = head[tp]; k != -1; k = nt[k]) {
                        int to = pnt[k];
                        if (visited[to]) continue;
                        visited[to] = true;
                        if (fir) {
                            fir = false;
                            val.push_back(ch[k]);
                            res[i] = to;
                            q[r++] = to; att[to] = ch[k];
                        }
                        else if (ch[k] > val.back()) {
                            val.back() = ch[k];
                            res[i] = to;
                            q[r++] = to; att[to] = ch[k];
                        }
                        else if (ch[k] == val.back()) {
                            if (to > res[i]) res[i] = to;
                            q[r++] = to; att[to] = ch[k];
                        }
                    }
                }
            }
            ++step;
        }
    }
    FOR(i, n) printf("%d ", res[i] + 1);
    printf("\n");
    return 0;
}
