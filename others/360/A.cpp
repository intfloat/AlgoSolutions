#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int T, N, sz, handle = 0;
set<pii> mem;
map<int, pii> allocated;
int allocate(int sz) {
    for (auto it = mem.begin(); it != mem.end(); ++it) {
        pii cur = *it;
        // printf("%d %d\n", cur.first, cur.second);
        if (cur.second - cur.first + 1 >= sz) {
            int nfirst = cur.first + sz;
            mem.erase(it);
            if (nfirst <= cur.second) mem.insert({nfirst, cur.second});
            ++handle;
            allocated[handle] = {cur.first, cur.first + sz - 1};
            return handle;
        }
    }
    return -1;
}
void del_h(int h) {
    auto it = allocated.find(h);
    if (it == allocated.end()) {
        printf("ILLEGAL_OPERATION\n");
        return;
    }
    pii val = it->second;
    allocated.erase(it);
    auto tt = mem.upper_bound(val);
    if (tt != mem.end()) {
        pii up = *tt;
        if (up.first == val.second + 1) {
            val.second = up.second;
            mem.erase(tt);
        }
    }
    tt = mem.upper_bound(val);
    if (tt != mem.begin()) {
        --tt;
        pii low = *tt;
        if (low.second + 1 == val.first) {
            val.first = low.first;
            mem.erase(tt);
        }
    }
    mem.insert(val);
}
void organize() {
    vector<pii> arr;
    for (auto it = allocated.begin(); it != allocated.end(); ++it) {
        arr.push_back(it->second);
    }
    sort(arr.begin(), arr.end());
    int ptr = 1;
    map<pii, pii> mp;
    FOR(i, arr.size()) {
        pii& val = arr[i];
        mp[val] = {ptr, ptr + val.second - val.first};
        ptr += val.second - val.first + 1;
    }
    mem.clear();
    if (ptr <= N) mem.insert({ptr, N});
    for (auto it = allocated.begin(); it != allocated.end(); ++it) {
        allocated[it->first] = mp[it->second];
    }
}
int main() {
    string op;
    int h;
    while (cin >> T >> N) {
        mem.clear(); allocated.clear(); handle = 0;
        mem.insert({1, N});
        FOR(i, T) {
            cin >> op;
            if (op == "new") {
                cin >> sz;
                int ret = allocate(sz);
                if (ret > 0) printf("%d\n", ret);
                else printf("NULL\n");
            } else if (op == "del") {
                cin >> h;
                del_h(h);
            } else {
                assert(op == "def");
                organize();
            }
        }
    }
    return 0;
}
