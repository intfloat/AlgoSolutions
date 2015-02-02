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
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define LEFT 0
#define RIGHT 1
using namespace std;

struct Node {
    int val, fix, sz;
    Node* ch[2];
    Node(int _v): val(_v), sz(1) {
        fix = rand();
        ch[0] = ch[1] = NULL;
    }
};

void update_sz(Node* &root) {
    if (root == NULL) return;
    root->sz = 1;
    if (root->ch[0] != NULL) root->sz += root->ch[0]->sz;
    if (root->ch[1] != NULL) root->sz += root->ch[1]->sz;
    return;
}

void rotate_treap(Node* &root, int kind) {
    Node* tmp = root->ch[kind ^ 1];
    root->ch[kind ^ 1] = tmp->ch[kind];
    tmp->ch[kind] = root;
    root = tmp;
    update_sz(root->ch[0]); update_sz(root->ch[1]); update_sz(root);
    return;
}

void insert_treap(Node* &root, int number) {
    if (root == NULL) {
        root = new Node(number);
        return;
    }
    if (number <= root->val) {
        insert_treap(root->ch[0], number);
        root->sz += 1;
        if (root->ch[0]->fix < root->fix)
            rotate_treap(root, RIGHT);        
    }
    else {
        insert_treap(root->ch[1], number);
        root->sz += 1;
        if (root->ch[1]->fix < root->fix)
            rotate_treap(root, LEFT);        
    }
    return;
}

int get_kth(Node* &root, int k) {
    assert(k <= root->sz);
    int left, right;
    if (root->ch[0] == NULL) left = 0;
    else left = root->ch[0]->sz;
    right = root->sz - 1 - left;    
    if (root->ch[1] != NULL)
        assert(right == root->ch[1]->sz);

    if (k <= left) return get_kth(root->ch[0], k);
    if (k == left + 1) return root->val;
    else return get_kth(root->ch[1], k - left - 1);
}

void delete_treap(Node* &root, int v) {
    assert(root != NULL);
    if (root->val > v) {
        delete_treap(root->ch[0], v);
        --(root->sz);
    }
    else if (root->val < v) {
        delete_treap(root->ch[1], v);
        --(root->sz);
    }
    else {
        if (root->ch[0] == NULL) root = root->ch[1];
        else if (root->ch[1] == NULL) root = root->ch[0];
        else if (root->ch[0]->fix < root->ch[1]->fix) {
            rotate_treap(root, RIGHT);
            delete_treap(root->ch[1], v);
            --(root->sz);
        }
        else {
            rotate_treap(root, LEFT);
            delete_treap(root->ch[0], v);
            --(root->sz);
        }
    }
    return;
}

int main() {
    int n, k, number;
    long long res = 0;
    scanf("%d", &n);
    Node * root = NULL;
    FOR(i, n) {
        scanf("%d", &k);
        FOR(j, k) {
            scanf("%d", &number);
            insert_treap(root, number);
        }
        int mx = get_kth(root, root->sz);
        int mn = get_kth(root, 1);
        res += mx - mn;
        // cout << mx << " " << mn << endl;
        delete_treap(root, mx);
        delete_treap(root, mn);
    }
    cout << res << endl;
    return 0;
}
