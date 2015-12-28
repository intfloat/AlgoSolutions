#include <string.h>
#include <stdio.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
const int MAX_N = 200005;
int tree[MAX_N * 4][10][10], n, ql, qr, same[MAX_N * 4], k;
int left[MAX_N * 4], right[MAX_N * 4], pos[11];
char s[MAX_N], nc, perm[11];
inline void pushdown(int ptr, int tot) {
    if (same[ptr] >= 0) {
        int l = ptr * 2, r = ptr * 2 + 1;
        same[l] = same[r] = same[ptr];
        left[ptr] = right[ptr] = left[l] = right[l] = left[r] = right[r] = same[ptr];
        memset(tree[ptr], 0, sizeof tree[ptr]);
        tree[ptr][same[ptr]][same[ptr]] = tot - 1;
        same[ptr] = -1;
    }
}
inline void pushup(int ptr) {
    int l = ptr * 2, r = ptr * 2 + 1;
    same[ptr] = -1;
    FOR(i, k) FOR(j, k) {
        tree[ptr][i][j] = tree[l][i][j] + tree[r][i][j];
    }
    ++tree[ptr][right[l]][left[r]];
    left[ptr] = left[l];
    right[ptr] = right[r];
}
void build_tree(int ptr, int l, int r) {
    left[ptr] = s[l] - 'a';
    right[ptr] = s[r] - 'a';
    memset(tree[ptr], 0, sizeof tree[ptr]);
    same[ptr] = -1;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build_tree(2 * ptr, l, mid);
    build_tree(2 * ptr + 1, mid + 1, r);
    pushup(ptr);
}
void update(int ptr, int l, int r) {
    if (r > l) pushdown(ptr, r - l + 1);
    if (ql > r || qr < l) return;
    if (l >= ql && r <= qr) {
        if (r > l) same[ptr] = nc - 'a';
        left[ptr] = right[ptr] = nc - 'a';
        memset(tree[ptr], 0, sizeof tree[ptr]);
        tree[ptr][nc - 'a'][nc - 'a'] = r - l;
        return;
    }
    int mid = (l + r) / 2;
    update(ptr * 2, l, mid);
    update(ptr * 2 + 1, mid + 1, r);
    pushup(ptr);
}
inline int query(int ptr) {
    int res = 0;
    FOR(i, k) FOR(j, k) {
        if (pos[i] >= pos[j]) {
            res += tree[ptr][i][j];
        }
    }
    ++res;
    return res;
}
int main() {
    int m, type;
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s", s);
    build_tree(1, 0, n - 1);
    FOR(i, m) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %c", &ql, &qr, &nc);
            --ql; --qr;
            update(1, 0, n - 1);
        }
        else {
            scanf("%s", perm);
            FOR(i, k) pos[perm[i] - 'a'] = i;
            printf("%d\n", query(1));
        }
    }
    return 0;
}
