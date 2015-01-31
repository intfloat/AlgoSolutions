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

bool check(const string& s1, const string& s2) {
    if (s1.size() > s2.size()) return true;
    assert(s1.size() == s2.size());
    FOR(i, s1.size()) {
        if (s1[i] > s2[i]) return true;
    }
    return false;
}

void change(string& cur) {
    assert(cur[0] > '0');
    int len = cur.size();
    int cnt = 0, pos = -1;
    for (int i = len - 1; i >= 0; --i) {
        if (cur[i] < '9' && cnt > 0) {
            ++cur[i]; --cur[pos]; return;
        }
        else if (cur[i] > '0' && cnt == 0) {
            ++cnt; pos = i;
        }
        else if (cnt > 0 && cur[i] == '9') {
            pos = i;
        }
    }
    // only one non-zero character
    --cur[0];
    cur = '1' + cur;
    return;
}

int total;
void solve(string& cur, const string& prev) {
    if (cur.size() > prev.size()) {
        total -= cur[0] - '0';
        for (int i = 1; i < cur.size(); ++i) cur[i] = '0';
        for (int i = cur.size() - 1; i >= 0; --i) {
            assert(i != 0);
            if (total == 0) break;
            if (total >= 9) {
                cur[i] = '9'; total -= 9;
            }
            else {
                cur[i] = '0' + total; total = 0; break;
            }
        }
        assert(total == 0);
        // assert(check(change, prev));
        return;
    }
    assert(cur.size() == prev.size());
    int used = 0;
    for (int i = 0; i < cur.size(); ++i) {
        if (cur[i] > prev[i]) {
            total -= used + (cur[i] - '0');
            for (int j = i + 1; j < cur.size(); ++j) cur[j] = '0';
            for (int i = cur.size() - 1; i >= 0; --i) {
                if (total == 0) break;
                if (total >= 9) {
                    cur[i] = '9'; total -= 9;
                }
                else {
                    cur[i] = '0' + total; total = 0; break;
                }
            }
            assert(total == 0);
            // assert(check(change, prev));
            return;
        }
        else {
            used += cur[i] - '0';
            continue;
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    FOR(i, n) cin >> arr[i];
    vector<string> res(n, "");    
    FOR(i, n) {
        total = arr[i];
        string cur = "";
        if (i == 0) {
            while (arr[i] >= 9) {
                cur += '9';
                arr[i] -= 9;
            }
            char c = '0' + arr[i];
            if (arr[i] > 0) cur = c + cur;
            res[i] = cur;
            continue;
        }
        string prev = res[i - 1];
        FOR(j, prev.size()) cur += '0';
        for (int j = 0; j < prev.size(); ++j) {
            if (arr[i] >= prev[j] - '0') {
                cur[j] = prev[j];
                arr[i] -= prev[j] - '0'; 
            }
            else {
                cur[j] = arr[i] + '0';
                arr[i] = 0;
                break;
            }
        }
        if (arr[i] > 0) {
            for (int j = cur.size() - 1; j >= 0; --j) {
                int inc = '9' - cur[j];
                if (arr[i] >= inc) {
                    cur[j] = '9'; arr[i] -= inc;
                }
                else {
                    cur[j] += arr[i]; arr[i] = 0; break;
                }
            }
            while (arr[i] >= 9) {
                cur = '9' + cur;
                arr[i] -= 9;
            }
            char c = '0' + arr[i];
            if (arr[i] > 0) cur = c + cur;
        }
        bool ok = check(cur, prev);
        if (ok) { res[i] = cur; continue; }
        while (!check(cur, prev)) {
            change(cur);
        }
        solve(cur, prev);
        res[i] = cur;
    }
    FOR(i, n) cout << res[i] << endl;
    return 0;
}
