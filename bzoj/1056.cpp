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

string name;
int score;

struct Node {
    int fix, sz;
    string name;
    pair<int, int> val;
    Node* ch[2];
    Node(pair<int, int> _v): val(_v), sz(1) {
        fix = rand();
        ch[0] = ch[1] = NULL;
    }
};

void update_sz(Node* &root) {
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

void insert_treap(Node* &root, pair<int, int>& v) {
    if (root == NULL) {
        root = new Node(v);
        root->name = name;
        return;
    }
    if (v < root->val) {
        insert_treap(root->ch[0], v);
        ++root->sz;
        if (root->ch[0]->fix < root->fix) rotate_treap(root, RIGHT);
    }
    else {
        insert_treap(root->ch[1], v);
        ++root->sz;
        if (root->ch[1]->fix < root->fix) rotate_treap(root, LEFT);
    }    
}

void delete_treap(Node* &root, pair<int, int>& v) {
    if (v < root->val) {
        delete_treap(root->ch[0], v);
        --root->sz; return;
    }
    else if (v > root->val) {
        delete_treap(root->ch[1], v);
        --root->sz; return;
    }
    else {
        if (root->ch[0] == NULL) root = root->ch[1];
        else if (root->ch[1] == NULL) root = root->ch[0];
        else {
            int kind = root->ch[0]->fix < root->ch[1]->fix;
            rotate_treap(root, kind);
            delete_treap(root->ch[kind], v);
            --root->sz;
        }
    }
}

int get_rank(Node* &root, pair<int, int>& v) {
    int left = 0;
    if (root->ch[0] != NULL) left = root->ch[0]->sz;
    if (v == root->val) return left + 1;
    if (v < root->val) return get_rank(root->ch[0], v);
    else return get_rank(root->ch[1], v) + left + 1;
}

string get_kth(Node* &root, int k) {
    // assert(k <= root->sz);
    int left = 0;
    if (root->ch[0] != NULL) left = root->ch[0]->sz;
    if (k <= left) return get_kth(root->ch[0], k);
    if (k == left + 1) return root->name;
    else return get_kth(root->ch[1], k - left - 1);
}

int main() {    
    // freopen("rank.in", "r", stdin);
    // freopen("rank.out", "w", stdout);
    int n, score;
    Node* root = NULL;
    // <name, <score, time-stamp> > pair
    map<string, pair<int, int> > records;
    char t[100];
    string s;
    scanf("%d", &n);    
    FOR(q, n) {
        scanf("%s", t);
        s = t;        
        if (s[0] == '+') {
            name = s.substr(1, s.size() - 1);
            scanf("%d", &score);
            pair<int, int> val = make_pair(score, -q);
            if (records.find(name) != records.end())
                delete_treap(root, records[name]);
            insert_treap(root, val);
            records[name] = val;
        }
        else {
            // assert(s[0] == '?');
            s = s.substr(1, s.size() - 1);
            if (records.find(s) != records.end()) {
                printf("%d\n", (int)records.size() - get_rank(root, records[s]) + 1);
            }
            else {                
                int left = 0, right, N = records.size();
                FOR(i, s.size()) left = left * 10 + (s[i] - '0');                
                right = min(left + 9, N);
                for (int i = left; i < right; ++i) {
                    printf("%s ", get_kth(root, N - i + 1).c_str());
                }
                printf("%s\n", get_kth(root, N - right + 1).c_str());                
            }
        }
    }
    return 0;
}
