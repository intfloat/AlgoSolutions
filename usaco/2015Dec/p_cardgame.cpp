#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
int N;
struct Node {
    int score, ours, rem;
    int l, r;
};
Node tree[100000 * 4 + 5];
void build_tree(int ptr, int low, int up) {
    if (low > up) return;
    tree[ptr].score = tree[ptr].ours = tree[ptr].rem = 0;
    tree[ptr].l = low; tree[ptr].r = up;
    if (low == up) return;
    int mid = (low + up) / 2;
    build_tree(ptr * 2, low, mid);
    build_tree(ptr * 2 + 1, mid + 1, up);
}
void update_tree(int ptr, int pos, bool us) {
    if (tree[ptr].l == pos && tree[ptr].r == pos) {
        if (us) ++tree[ptr].ours;
        else ++tree[ptr].rem;
        return;
    }
    int mid = (tree[ptr].l + tree[ptr].r) / 2;
    if (pos <= mid) update_tree(ptr * 2, pos, us);
    else update_tree(ptr * 2 + 1, pos, us);
    int extra = min(tree[ptr * 2].rem, tree[ptr * 2 + 1].ours);
    tree[ptr].score = tree[ptr * 2].score + tree[ptr * 2 + 1].score + extra;
    tree[ptr].ours = tree[ptr * 2].ours + tree[ptr * 2 + 1].ours - extra;
    tree[ptr].rem = tree[ptr * 2].rem + tree[ptr * 2 + 1].rem - extra;
}
vector<int> solve(vector<int>& bessie, vector<int>& elsie) {
    assert(N == (int)bessie.size() && N == (int)elsie.size());
    vector<int> ret;
    build_tree(1, 1, 2 * N);
    FOR(i, bessie.size()) {
        update_tree(1, bessie[i], true);
        update_tree(1, elsie[i], false);
        ret.push_back(tree[1].score);
    }
    return ret;
}
int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int id;
    scanf("%d", &N);
    vector<bool> used(2 * N + 1, false);
    vector<int> bessie, elsie(N);
    FOR(i, N) {
        scanf("%d", &id);
        used[id] = true;
        elsie[i] = id;
    }
    for (int i = 1; i <= 2 * N; ++i) {
        if (!used[i]) {
            bessie.push_back(i);
        }
    }
    sort(bessie.begin(), bessie.end(), greater<int>());
    vector<int> res1 = solve(bessie, elsie);
    reverse(elsie.begin(), elsie.end());
    reverse(bessie.begin(), bessie.end());
    FOR(i, N) {
        elsie[i] = 2 * N + 1 - elsie[i];
        bessie[i] = 2 * N + 1 - bessie[i];
    }
    vector<int> res2 = solve(bessie, elsie);
    int res = max(res1[N - 1], res2[N - 1]);
    for (int i = 0; i < N - 1; ++i) {
        res = max(res, res1[i] + res2[N - 2 - i]);
    }
    printf("%d\n", res);
    return 0;
}
