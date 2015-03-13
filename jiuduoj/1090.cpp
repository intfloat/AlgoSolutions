/**
input:
4
a\b\c
a\d\e
b\cst
d\
0

output:
a
 b
  c
  cst
 d
  e

it will not get AC for this problem, but I think combining
global information is much more meaningful in realistic situations.
**/
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

void split(const string& s, vector<string>& res) {
    res.clear();
    int prev = -1;
    FOR(i, s.size()) {
        if (s[i] == '\\') {
            string cur = s.substr(prev + 1, i - prev - 1);
            if (!cur.empty()) {
                res.push_back(cur);                
            }
            prev = i;
        }
    }
    if (prev + 1 != s.size()) {
        res.push_back(s.substr(prev + 1, s.size() - prev - 1));
    }
    return;
}

map<string, set<string> > dict;
void print_rec(string key, int depth) {
    set<string>& st = dict[key];
    set<string>::iterator it = st.begin();
    FOR(i, depth) cout << " ";
    cout << key << endl;
    for (; it != st.end(); ++it) {
        print_rec(*it, depth + 1);
    }
    return;
}

int main() {
    int N;
    while (cin >> N && N) {
        dict.clear();    
        set<string> internal;
        string s;
        vector<string> path;
        FOR(i, N) {
            cin >> s;
            split(s, path);
            for (int j = 0; j < static_cast<int>(path.size()) - 1; ++j) {
                if (dict.find(path[j]) == dict.end()) dict[path[j]] = set<string>();
                dict[path[j]].insert(path[j + 1]);
                internal.insert(path[j + 1]);
            }
            if (!path.empty() && dict.find(path.back()) == dict.end()) {
                dict[path.back()] = set<string>();
                internal.insert(path.back());
            }
        }
        map<string, set<string> >::iterator it;
        for (it = dict.begin(); it != dict.end(); ++it) {
            string key = it->first;
            if (internal.find(key) != internal.end()) continue;
            print_rec(key, 0);
        }
    }
    return 0;
}
