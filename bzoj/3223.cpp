#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define LEFT 0
#define RIGHT 1
using namespace std;
typedef int E;
struct Node {
    int fix, sz;
    E num;
    bool rev;
    Node* ch[2];
    Node(E _num): sz(1), num(_num) {
        fix = rand();
        ch[0] = ch[1] = NULL;
        rev = false;
    }
};
inline void pushdown(Node* &root) {
    if (root != NULL && root->rev) {
        swap(root->ch[0], root->ch[1]);
        if (root->ch[0] != NULL) root->ch[0]->rev = !(root->ch[0]->rev);
        if (root->ch[1] != NULL) root->ch[1]->rev = !(root->ch[1]->rev);
        root->rev = false;
    }
}
inline void update_sz(Node* &root) {
    if (root == NULL) return;
    root->sz = 1;
    if (root->ch[0] != NULL) root->sz += root->ch[0]->sz;
    if (root->ch[1] != NULL) root->sz += root->ch[1]->sz;
}
inline void rotate_treap(Node* &root, int kind) {
    if (root->rev) kind ^= 1;
    pushdown(root); pushdown(root->ch[0]); pushdown(root->ch[1]);
    Node* tmp = root->ch[kind ^ 1];
    root->ch[kind ^ 1] = tmp->ch[kind];
    tmp->ch[kind] = root;
    root = tmp;
    update_sz(root->ch[0]); update_sz(root->ch[1]); update_sz(root);
}
int nfix = -1;
void insert_treap(Node* &root, E r, E num) {
    pushdown(root);
    if (root == NULL) {
        root = new Node(num);
        if (nfix != -1) root->fix = nfix;
        return;
    }
    int left = 0;
    if (root->ch[0] != NULL) left = root->ch[0]->sz;
    if (r <= left + 1) {
        insert_treap(root->ch[0], r, num);
        ++root->sz;
        if (root->ch[0]->fix < root->fix) rotate_treap(root, RIGHT);
    }
    else {
        insert_treap(root->ch[1], r - left - 1, num);
        ++root->sz;
        if (root->ch[1]->fix < root->fix) rotate_treap(root, LEFT);
    }
}
void delete_treap(Node* &root, E r) {
    pushdown(root);
    int left = 0;
    if (root->ch[0] != NULL) left = root->ch[0]->sz;
    if (r <= left) {
        delete_treap(root->ch[0], r);
        --root->sz; return;
    }
    else if (r > left + 1) {
        delete_treap(root->ch[1], r - left - 1);
        --root->sz; return;
    }
    else {
        if (root->ch[0] == NULL) root = root->ch[1];
        else if (root->ch[1] == NULL) root = root->ch[0];
        else {
            int kind = root->ch[0]->fix < root->ch[1]->fix;
            rotate_treap(root, kind);
            delete_treap(root, r);
            --root->sz;
        }
    }
}
Node* get_kth(Node* &root, int k) {
    pushdown(root);
    int left = 0;
    if (root->ch[0] != NULL) left = root->ch[0]->sz;
    if (k <= left) return get_kth(root->ch[0], k);
    if (k == left + 1) return root;
    else return get_kth(root->ch[1], k - left - 1);
}
int main() {
    srand(1234);
    int n, m, l, r;
    scanf("%d %d", &n, &m);
    Node* root = NULL;
    for (int i = 1; i <= n + 2; ++i) {
        insert_treap(root, i, i - 1);
    }
    int mn = -10;
    FOR(j, m) {
        scanf("%d %d", &l, &r);
        int nl = get_kth(root, l)->num;
        delete_treap(root, l); nfix = mn - 2; insert_treap(root, l, nl);
        int nr = get_kth(root, r + 2)->num;
        delete_treap(root, r + 2); nfix = mn - 1; insert_treap(root, r + 2, nr);
        root->ch[1]->ch[0]->rev = !(root->ch[1]->ch[0]->rev);
        mn -= 2;
    }
    for (int i = 1; i <= n; ++i) {
        if (i == 1) printf("%d", get_kth(root, i + 1)->num);
        else printf(" %d", get_kth(root, i + 1)->num);
    }
    return 0;
}
