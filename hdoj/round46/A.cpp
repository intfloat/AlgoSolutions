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
using namespace std;
typedef long long ll;
struct Node {
    int h, m, s;
    Node(int _h, int _m, int _s): h(_h), m(_m), s(_s) {}
};
string get(int num) {
    string ret = "";
    FOR(i, 2) {
        ret.push_back('0' + num % 10);
        num /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string to_str(Node& node) {
    string ret = "";
    ret += get(node.h) + ":" + get(node.m) + ":" + get(node.s);
    return ret;
}
int main() {
    map<int, vector<Node> > mp;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 60; ++j) {
            for (int k = 0; k < 60; k += 10) {
                int d1 = 360000 * i + 100 * (60 * j + k);
                int d2 = 72000 * j + 1200 * k;
                if (d1 < d2) swap(d1, d2);
                int dd = d1 - d2;
                if (dd > 180 * 12000) {
                    dd = 360 * 12000 - dd;
                }
                if (mp.find(dd) == mp.end()) {
                    mp[dd] = vector<Node>();
                }
                mp[dd].push_back(Node(i, j, k));
            }
        }
    }
    int d;
    while (cin >> d) {
        if (mp.find(d) != mp.end()) {
            vector<Node>& res = mp[d];
            FOR(i, res.size()) {
                cout << to_str(res[i]) << endl;
            }
        }
    }
    return 0;
}
