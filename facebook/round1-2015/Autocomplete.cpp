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

struct Node {    
    Node* ptr[26];
    Node() { FOR(i, 26) ptr[i] = NULL; }
};
Node* root = NULL;
vector<Node *> v;

int insert_trie(const string& s) {
    Node* cur = root;
    int ret = -1;
    short int pos;
    FOR(i, s.size()) {
        pos = s[i] - 'a';
        if (cur->ptr[pos] == NULL) {
            if (ret < 0) ret = i + 1;
            cur->ptr[pos] = new Node();
            v.push_back(cur->ptr[pos]);
        }
        cur = cur->ptr[pos];
    }
    if (ret < 0) return s.size();
    else return ret;
}

int main() {
    int T, N;
    string s;
    cin >> T;
    FOR(tt, T) {
        // if (root != NULL) delete root;
        root = new Node();
        v.push_back(root);
        long long res = 0;
        cin >> N;
        FOR(i, N) {
            cin >> s;
            res += insert_trie(s);
        }
        cout << "Case #" << tt + 1 << ": " << res << endl;
        FOR(i, v.size()) if (v[i] != NULL) delete v[i];
        v.clear();
    }
    return 0;
}
