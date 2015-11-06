#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define LEFT 0
#define RIGHT 1
using namespace std;
typedef int E;
const int MIN = INT_MIN / 2;
const int INF = INT_MAX / 2;
struct Node {
    int fix, sz;
    E val;
    Node* ch[2];
    Node(E _v): sz(1), val(_v) {
        fix = rand();
        ch[0] = ch[1] = NULL;
    }
};
inline void update_sz(Node* &root) {
    if (root == NULL) return;
    root->sz = 1;
    if (root->ch[0] != NULL) root->sz += root->ch[0]->sz;
    if (root->ch[1] != NULL) root->sz += root->ch[1]->sz;
}
void rotate_treap(Node* &root, int kind) {
    Node* tmp = root->ch[kind ^ 1];
    root->ch[kind ^ 1] = tmp->ch[kind];
    tmp->ch[kind] = root;
    root = tmp;
    update_sz(root->ch[0]); update_sz(root->ch[1]); update_sz(root);
}
void insert_treap(Node* &root, E& v) {
    if (root == NULL) {
        root = new Node(v);
        return;
    }
    if (v < root->val) {
        insert_treap(root->ch[0], v);
        update_sz(root);
        if (root->ch[0]->fix < root->fix) rotate_treap(root, RIGHT);
    }
    else {
        insert_treap(root->ch[1], v);
        update_sz(root);
        if (root->ch[1]->fix < root->fix) rotate_treap(root, LEFT);
    }
}
void delete_treap(Node* &root, E& v) {
    if (root == NULL) return;
    if (v < root->val) {
        delete_treap(root->ch[0], v);
        update_sz(root);
        return;
    }
    else if (v > root->val) {
        delete_treap(root->ch[1], v);
        update_sz(root); return;
    }
    else if (v == root->val) {
        if (root->ch[0] == NULL) root = root->ch[1];
        else if (root->ch[1] == NULL) root = root->ch[0];
        else {
            int kind = root->ch[0]->fix < root->ch[1]->fix;
            rotate_treap(root, kind);
            delete_treap(root->ch[kind], v);
            update_sz(root);
        }
    }
}
int get_rank(Node* &root, E& v) {
    if (root == NULL) return 1;
    int left = 0;
    if (root->ch[0] != NULL) left = root->ch[0]->sz;
    if (v == root->val) return min(left + 1, get_rank(root->ch[0], v));
    if (v < root->val) return min(left + 1, get_rank(root->ch[0], v));
    else return get_rank(root->ch[1], v) + left + 1;
}
Node* get_kth(Node* &root, int k) {
    int left = 0;
    if (root->ch[0] != NULL) left = root->ch[0]->sz;
    if (k <= left) return get_kth(root->ch[0], k);
    if (k == left + 1) return root;
    else return get_kth(root->ch[1], k - left - 1);
}
int get_pre(Node* &root, E x) {
    if (root == NULL) return MIN;
    if (root->val < x) {
        return max(root->val, get_pre(root->ch[1], x));
    }
    else return get_pre(root->ch[0], x);
}
int get_next(Node* &root, E x) {
    if (root == NULL) return INF;
    if (root->val > x) {
        return min(root->val, get_next(root->ch[0], x));
    }
    else return get_next(root->ch[1], x);
}
int main() {
    srand(1234);
    int n, type, x;
    Node* root = NULL;
    scanf("%d", &n);
    FOR(i, n) {
        scanf("%d %d", &type, &x);
        if (type == 1) {
            insert_treap(root, x);
        }
        else if (type == 2) {
            delete_treap(root, x);
        }
        else if (type == 3) {
            printf("%d\n", get_rank(root, x));
        }
        else if (type == 4) {
            printf("%d\n", get_kth(root, x)->val);
        }
        else if (type == 5) {
            printf("%d\n", get_pre(root, x));
        }
        else if (type == 6) {
            printf("%d\n", get_next(root, x));
        }
    }
    return 0;
}
