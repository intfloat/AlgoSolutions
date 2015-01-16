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

const int MAX_N = 100005;
int val[MAX_N], ch[MAX_N][2], pre[MAX_N];
int ptr = 0, root;

int add_node(int p, int num) {
    val[++ptr] = num;
    ch[ptr][LEFT] = ch[ptr][RIGHT] = 0;
    pre[ptr] = p;
    if (val[p] < num) ch[p][RIGHT] = ptr;
    else ch[p][LEFT] = ptr;
    return ptr;
}

int get_dir(int idx, int child) {
    if (ch[idx][LEFT] == child) return LEFT;
    else return RIGHT;
}

void rotate(int idx, int kind) {
    // assert(kind == LEFT || kind == RIGHT);
    int p = pre[idx];
    ch[p][!kind] = ch[idx][kind];
    pre[ch[idx][kind]] = p;
    if (pre[p]) {
        if (get_dir(pre[p], p) == LEFT) ch[pre[p]][LEFT] = idx;
        else ch[pre[p]][RIGHT] = idx;
    }
    pre[idx] = pre[p];
    ch[idx][kind] = p;
    pre[p] = idx;
    return;
}

void splay(int cur, int goal) {
    while (pre[cur] != goal) {
        int p = pre[cur];
        if (pre[p] == goal) {
            if (get_dir(p, cur) == LEFT) rotate(cur, RIGHT);
            else rotate(cur, LEFT);
            break;
        }
        int dir1 = get_dir(pre[p], p);
        int dir2 = get_dir(p, cur);
        if (dir1 == dir2) {
            rotate(p, !dir1);
            rotate(cur, !dir2);
        }
        else {
            rotate(cur, !dir2);
            rotate(cur, !dir1);
        }
    }
    if (goal == 0) root = cur;
    return;
}

bool insert_node(int num) {
    if (ptr == 0) {
        root = add_node(0, num);
        return true;
    }
    int cur = root;
    while (true) {
        if (val[cur] == num) {
            splay(cur, 0);
            return false; 
        }
        if (val[cur] < num && ch[cur][RIGHT] == 0) {
            int idx = add_node(cur, num);
            splay(idx, 0);
            return true;
        }
        if (val[cur] > num && ch[cur][LEFT] == 0) {
            int idx = add_node(cur, num);
            splay(idx, 0);
            return true;
        }
        if (val[cur] < num) cur = ch[cur][RIGHT];
        else cur = ch[cur][LEFT];
    }
    return true;
}

const int INF = INT_MAX / 2;
int get_pre() {
    if (ch[root][LEFT] == 0) return INF;
    int cur = ch[root][LEFT];
    while (ch[cur][RIGHT]) cur = ch[cur][RIGHT];    
    return val[cur];
}

int get_next() {
    if (ch[root][RIGHT] == 0) return INF;
    int cur = ch[root][RIGHT];
    while (ch[cur][LEFT]) cur = ch[cur][LEFT];
    return val[cur];
}

int main() {
    int n, t;
    long long res = 0;
    while (scanf("%d", &n) != EOF) {
        ptr = 0, res = 0;
        FOR(i, n) {
            // in case there are duplicate elements
            if (scanf("%d", &t) == EOF) t = 0;
            if (!insert_node(t)) continue;
            int low = get_pre();
            int up = get_next();
            int cur = INT_MAX;
            // cout << low << " " << up << endl;
            if (low != INF) cur = min(cur, t - low);
            if (up != INF) cur = min(cur, up - t);
            if (cur != INT_MAX) res += cur;
            else res += t;
            // cout << "debug: " << res << endl;
        }
        printf("%lld\n", res);
    }
    return 0;
}
