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
#include <stdio.h>
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

void update_sz(Node* & root) {
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
    return;
}

void insert_treap(Node* &root, int v) {
    if (root == NULL) {
        root = new Node(v);
        return;
    }
    int kind = v > root->val;
    insert_treap(root->ch[kind], v);
    ++root->sz;
    if (root->fix > root->ch[kind]->fix)
        rotate_treap(root, kind ^ 1);
    return;
}

// delete all nodes with value < baseline
void delete_treap(Node* &root, const int baseline) {
    if (root == NULL) return;
    if (root->val < baseline) {
        root = root->ch[1];
        delete_treap(root, baseline);
        update_sz(root);
    }
    else {
        delete_treap(root->ch[0], baseline);
        update_sz(root);
    }
}

int get_kth(Node* &root, int k) {    
    int left = 0;
    if (root->ch[0] != NULL) left = root->ch[0]->sz;
    if (k <= left) return get_kth(root->ch[0], k);
    else if (k == left + 1) return root->val;
    else return get_kth(root->ch[1], k - left - 1);
}

int main() {
    int n, mn, base, total = 0;
    scanf("%d %d", &n, &mn);
    Node* root = NULL;
    base = mn;
    FOR(tt, n) {
        char command;
        int number;
        scanf(" %c %d", &command, &number);
        if (command == 'I') {            
            if (number < mn) continue;
            ++total;
            insert_treap(root, number - base);
        }
        else if (command == 'A') base += number;
        else if (command == 'S') {
            base -= number;
            delete_treap(root, mn - base);
        }
        else if (command == 'F') {
            if (root == NULL || number > root->sz || number < 1) printf("-1\n");
            else {
                number = root->sz - number + 1;
                printf("%d\n", get_kth(root, number) + base);
            }            
        }
    }
    if (root != NULL) total = total - root->sz;
    // total number of stuff that left company
    printf("%d\n", total);
    return 0;
}
