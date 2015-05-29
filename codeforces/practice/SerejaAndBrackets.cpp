#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int MAX_N = 1000005;
char s[MAX_N];
int n, root = 1, q;
int rl[MAX_N * 3], rr[MAX_N * 3], cnt[MAX_N * 3];
void build_tree(int cur, int left, int right) {    
    if (left == right) {
        rl[cur] = (s[left] == '(');
        rr[cur] = (s[left] == ')');
        cnt[cur] = 0;
        return;
    }
    int mid = (left + right) / 2;
    build_tree(2 * cur, left, mid);
    build_tree(2 * cur + 1, mid + 1, right);
    cnt[cur] = cnt[2 * cur] + cnt[2 * cur + 1];
    int dt = min(rl[2 * cur], rr[2 * cur + 1]);
    cnt[cur] += dt;
    rl[cur] = rl[2 * cur] + rl[2 * cur + 1] - dt;
    rr[cur] = rr[2 * cur] + rr[2 * cur + 1] - dt;
    return;
}
typedef tuple<int, int, int> RET;
RET query(int cur, int left, int right, int x, int y) {    
    if (left == x && right == y) return make_tuple(rl[cur], rr[cur], cnt[cur]);
    int mid = (x + y) / 2;
    if (right <= mid) return query(2 * cur, left, right, x, mid);
    if (left > mid) return query(2 * cur + 1, left, right, mid + 1, y);    
    RET res1 = query(2 * cur, left, mid, x, mid);
    RET res2 = query(2 * cur + 1, mid + 1, right, mid + 1, y);
    int dt = min(get<0>(res1), get<1>(res2));
    return make_tuple(get<0>(res1) + get<0>(res2) - dt, 
                      get<1>(res1) + get<1>(res2) - dt,
                      get<2>(res1) + get<2>(res2) + dt);
}
int main() {
    int l, r;
    scanf("%s", s);
    n = strlen(s);    
    build_tree(root, 0, n - 1);    
    scanf("%d", &q);
    FOR(i, q) {
        scanf("%d %d", &l, &r);
        --l; --r;
        printf("%d\n", 2 * get<2>(query(root, l, r, 0, n - 1)));
    }
    return 0;
}
